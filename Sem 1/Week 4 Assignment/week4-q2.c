// WAP to find factorial value of any number entered through keyboard.
#include <stdio.h>
int main()
{
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
}