#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char alph_upper[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P','Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char alph_lower[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p','q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int shift;
    int count = 0;
    string check = argv[1];
    if ( argc != 2 )
    {
        printf ("usage : ./vigenere k \n");
        return 1;
    }
    for (int a = 0; a < strlen(check); a++)
    {
        int input = check[a];
        if (((input >= 32 && input <= 64) == 1) || ((input >= 91 && input <= 96) == 1) || ((input >= 123 && input <= 126) == 1))
        {
            printf ("usage : ./vigenere k \n");
            return 1;
        }
    }
    string key = argv[1];
    string plain_text = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plain_text); i++)
    {
        if (((plain_text[i] >= 32 && plain_text[i] <= 64) == 1) || ((plain_text[i] >= 91 && plain_text[i] <= 96) == 1) || ((plain_text[i] >= 123 && plain_text[i] <= 126) == 1))
        {
            printf("%c", plain_text[i]);
            count++;

        } else
        {
            if (i < strlen(key))
            {
                shift = key[i];
            } else
            {
                if (count == 0)
                {
                    shift = key[(i - strlen(key)) % strlen(key)];
                } else
                {
                    shift = key[((i - count) - strlen(key)) % strlen(key)];
                }
            }

            if ((shift >= 65 & shift <= 90) == 1)
            {
                shift = shift - 65;
            }
            else if ((shift >= 97 & shift <= 122) == 1)
            {
                shift = shift - 97;
            } else
            {
                exit(0);
            }
        }
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
    }
printf("\n");
}