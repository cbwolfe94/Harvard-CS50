/*
Conner Wolfe
PSet4 Recover
4/9/18
Program that recovers jpeg(s) from forensic image.
*/
#include <stdio.h>
#include <cs50.h>
#include <stdint.h>



int main(int argc, char* argv[])
{

    //initialize inptr, outptr, jpeg count, and block array
    FILE* inptr = fopen(argv[1],"r");
    FILE* outptr = NULL;
    int count = 0;
    uint8_t block[512];

    //prints error message if number of arguments does not equal 2
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    //prints error message if input file is invalid
    if (inptr == NULL)
    {
        printf("Could not open card.raw\n");
        return 2;
    }

    //while loop for indexing through card.raw
    while (fread(&block, 512, 1, inptr) == 1)
    {
        // if statement to make sure the file we are looking is a jpeg based off first four numbers in file
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] >= 0xe0 && block[3] <= 0xec))
        {
            if (outptr != NULL)
            {
                fclose(outptr);
            }
            //create an array 'name' that is length 8 that will then be the name of the file that is extracted from the raw file
            char name[8];
            //print the name of file
            sprintf(name,"%03d.jpg", count);
            outptr = fopen(name, "w");
            //write what is in block to outptr
            fwrite(block, sizeof(block), 1, outptr);
            //increment count for name of file
            count ++;
        }

        //
        else if (count > 0)
        {

            fwrite(block, sizeof(block), 1, outptr);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);


return 0;
}
