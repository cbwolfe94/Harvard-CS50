#include <cs50.h>
#include <stdio.h>


int main(void)
{

    int block_height = get_int("Please enter the height of the half pyramid: ");
    if (block_height < 23)
    {
        for (int i = 0; i < block_height; i += 1)
           {
               for (int j = 0; j < block_height - i - 1; j += 1)
                {
                   printf(" ");
                }
               for (int k = 0; k < i + 2; k += 1)
                {

                    printf("#");

                }
                printf("\n");
           }
    }

}