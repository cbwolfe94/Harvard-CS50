#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char alph_upper[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P','Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char alph_lower[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p','q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    if ( argc != 2 )
    {
        printf ("usage : ./caesar + key \n");
        return 1;
    }
    int shift = atoi(argv[1]);
    shift = shift % 26;
    if (argc == 2)
    {
        string plain_text = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0; i < strlen(plain_text); i ++)
        {
            int comp_char_1 = plain_text[i];
            if ((comp_char_1 >= 65 & comp_char_1 <= 90) == 1)
            {
                for (int j = 0; j < strlen(alph_upper); j++)
                {
                    int comp_char_2 = alph_upper[j];
                    if (comp_char_1 == comp_char_2)
                    {
                        if ((comp_char_1 + shift) > 90)
                        {
                            plain_text[i] = alph_upper[shift - (91 - comp_char_1)];
                            printf("%c", plain_text[i]);
                            break;

                        } else
                        {
                            plain_text[i] = alph_upper[j + shift];
                            printf("%c", plain_text[i]);
                            break;
                        }
                    }
                }
            }
            if ((comp_char_1 >= 97 & comp_char_1 <= 122) == 1)
            {
                for (int j = 0; j < strlen(alph_lower); j++)
                {
                    int comp_char_2 = alph_lower[j];
                    if (comp_char_1 == comp_char_2)
                    {
                        if ((comp_char_1 + shift) > 122)
                        {
                            plain_text[i] = alph_lower[shift - (123 - comp_char_1)];
                            printf("%c", plain_text[i]);
                            break;

                        } else
                        {
                            plain_text[i] = alph_lower[j + shift];
                            printf("%c", plain_text[i]);
                            break;
                        }
                    }
                }
            }
            else if (((comp_char_1 >= 32 && comp_char_1 <= 64) == 1) || ((comp_char_1 >= 91 && comp_char_1 <= 96) == 1) || ((comp_char_1 >= 123 && comp_char_1 <= 126) == 1))
            {
                printf("%c", plain_text[i]);
            }
        }
        printf("\n");
    }
}