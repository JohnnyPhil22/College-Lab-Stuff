// Write a menu driven program which has following options: 1. Factorial of a number, 2. Prime or not, 3. Odd or even, 4. Exit. Once a menu item is selected the appropriate action should be taken and once this action is finished, the menu should reappear. Unless the user selects the Exit option the program should continue to work.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    while (1)
    {
        printf("1. Factorial of number\n2. Prime number or not\n3. Odd or even number\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int n, ori, fac = 1;
            printf("Enter number to find factorial: ");
            scanf("%d", &n);
            ori = n;
            while (n > 0)
            {
                fac *= n;
                n -= 1;
            }
            printf("Factorial of %d = %d\n", ori, fac);
            break;

        case 2:
            int num, i, flag = 0;
            printf("Enter a positive integer: ");
            scanf("%d", &num);

            if (num == 0 || num == 1)
            {
                flag = 1;
            }

            for (i = 2; i <= num / 2; i++)
            {
                if (num % i == 0)
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                printf("%d is a prime number.\n", num);
            }
            else
            {
                printf("%d is not a prime number.\n", num);
            }
            break;

        case 3:
            int number;
            printf("Enter number: ");
            scanf("%d", &number);

            if (number % 2 == 0)
            {
                printf("%d is even number\n", number);
            }
            else
            {
                printf("%d is odd number\n", number);
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Entered wrong choice\n");
        }
    }
}