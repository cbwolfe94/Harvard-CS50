#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main(void)
{

    int total_amount_of_coins = 0;

    double amount = get_float("Enter the amount of change that you want: ");
    amount = round(amount * 100.0)/100.0;
    int correct_amount = amount *100;
    while (correct_amount > 0)
        {
            if (correct_amount >= 25)
                {
                    correct_amount -= 25;
                    total_amount_of_coins += 1;
                } else if (correct_amount >= 10 && correct_amount < 25)
                {
                    correct_amount -= 10;
                    total_amount_of_coins += 1;
                } else if (correct_amount >= 5 && correct_amount < 10)
                {
                    correct_amount -= 5;
                    total_amount_of_coins += 1;
                } else if (correct_amount > 0 && correct_amount < 5)

                {
                    correct_amount -= 1;
                    total_amount_of_coins += 1;
                } else
                {
                    break;
                }
        }
    printf("%d\n", total_amount_of_coins);
}