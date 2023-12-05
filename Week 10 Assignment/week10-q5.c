// Write a C program that receives a Credit Card number and checks using Luhn's rule whether the Credit Card number is valid.
#include <stdio.h>

int isValidCreditCard(const char *creditCardNumber)
{
    int sum = 0;
    int isSecondDigit = 0;

    for (int i = 15; i >= 0; --i)
    {
        int digit = creditCardNumber[i] - '0';

        if (isSecondDigit)
        {
            digit *= 2;

            if (digit > 9)
            {
                digit -= 9;
            }
        }

        sum += digit;
        isSecondDigit = !isSecondDigit;
    }

    return (sum % 10 == 0);
}

int main()
{
    char creditCardNumber[17];

    printf("Enter the Credit Card number (16 digits): ");
    scanf("%s", creditCardNumber);

    if (isValidCreditCard(creditCardNumber))
    {
        printf("Valid Credit Card number!\n");
    }
    else
    {
        printf("Invalid Credit Card number.\n");
    }
}