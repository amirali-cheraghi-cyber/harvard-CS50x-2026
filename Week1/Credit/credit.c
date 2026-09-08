#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card = get_long("Number: ");
    long temp = card;
    int sum = 0;
    int count = 0;

    while (temp > 0)
    {
        int digit = temp % 10;
        count++;

        if (count % 2 == 0)
        {
            digit *= 2;
            sum += digit / 10 + digit % 10;
        }
        else
        {
            sum += digit;
        }

        temp /= 10;
    }

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    long start = card;

    while (start >= 100)
    {
        start /= 10;
    }

    int first_two_digits = start;
    int first_digit = first_two_digits / 10;

    if (count == 15 && (first_two_digits == 34 || first_two_digits == 37))
    {
        printf("AMEX\n");
    }
    else if (count == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((count == 13 || count == 16) && first_digit == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
