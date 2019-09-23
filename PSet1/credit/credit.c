#include <cs50.h>
#include <stdio.h>
#include <string.h>

void reverseArray(char name[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = name[start];
        name[start] = name[end];
        name[end] = temp;
        start++;
        end--;

    }
}

int main(void)
{

    char name[100];
    int len;
    int result = 0;
    bool authorization = 0;
    long long card_number = get_long_long("Number:");
    sprintf(name, "%lld", card_number);
    len = strlen(name);
    reverseArray(name, 0, len - 1);
    for (int i = 0; i < len; i ++)
    {
        char mychar = name[i];

        int x = atoi(&mychar);
        if (i % 2 == 0)
        {
            result = result + x;
        } else
        {
                int t = x*2;
                int sum = 0;
                int rem;
            while (t!= 0)
            {
                rem = t% 10;
                sum = sum + rem;
                t = t/10;
            }
            result = result + sum;
        }

    }
    result = result % 10;

    if (result == 0)
    {
        authorization = 1;
    }

    if (result != 0)
    {
        authorization = 0;
    }

    if (authorization == 1 && name[len - 1] == '3')
    {
        printf("AMEX\n");
    } else if (authorization == 1 && name[len - 1] == '5')
    {
        printf("MASTERCARD\n");
    } else if (authorization == 1 && name[len - 1] == '4')
    {
        printf("VISA\n");
    } else
    {
        printf("INVALID\n");
    }

}
