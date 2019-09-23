// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize scale infile outfile\n");
        return 1;
    }
if (n <= 0 || n > 100)
    {
        printf("The value provided as the size must be that of a positive integer less than or equal to 100!\n");
        return 2;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }




    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int img_height = bi.biHeight;
    int img_width = bi.biWidth;
    bi.biHeight *= n;
    bi.biWidth *= n;
    int resized_height = bi.biHeight;
    int resized_width = bi.biWidth;

    int new_padding = (4 - (resized_width * sizeof(RGBTRIPLE)) % 4) % 4;

    //bf.bfSize = (sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bi.biWidth*abs(bi.biHeight)*(pow(n, 2)*sizeof(RGBTRIPLE)));
    //bi.biSizeImage = (bi.biWidth*abs(bi.biHeight)*(pow(n, 2)*sizeof(RGBTRIPLE)));
    bi.biSizeImage = ((resized_width * sizeof(RGBTRIPLE) + new_padding) * abs(resized_height));
    bf.bfSize = bi.biSizeImage + (sizeof(BITMAPINFOHEADER) + sizeof(BITMAPFILEHEADER));
       // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int outer_index = 0, biHeight = abs(img_height); outer_index < biHeight; outer_index++)
    {
        int img_width_ref;

        long offset = sizeof(RGBTRIPLE);
        // temporary storage
        RGBTRIPLE triple;

       // iterate over pixels in scanline
       for (int inner_index = 0; inner_index < n - 1; inner_index++)
        {
            for (img_width_ref = 0; img_width_ref < img_width; img_width_ref++)
            {



                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                for (int write_index = 0; write_index < n; write_index++)
                {// write RGB triple to outfile

                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

                }

            }

            for (int outfile_padding_index = 0; outfile_padding_index < new_padding; outfile_padding_index++)
            {
                fputc(0x00, outptr);
            }
            fseek(inptr,-1 * offset * img_width_ref,SEEK_CUR);
        }

        for (img_width_ref = 0; img_width_ref < img_width; img_width_ref++)
        {
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            for (int write_index = 0; write_index < n; write_index++)
            {// write RGB triple to outfile
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }

        }
        for (int outfile_padding_index = 0; outfile_padding_index < new_padding; outfile_padding_index++)
        {
            fputc(0x00, outptr);
        }

        //fseek(outptr, new_padding, SEEK_CUR);
        // then add it back (to demonstrate how)
        fseek(inptr, padding, SEEK_CUR);
    }


    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
