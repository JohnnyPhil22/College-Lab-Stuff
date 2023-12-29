// WAP to print nth fibonacci number.
#include <stdio.h>
int main()
{
    int n, a = 0, b = 1, c, i;
    printf("Enter which term you want: ");
    scanf("%d", &n);

    if (n == 0)
        printf("%d", a);
    for (i = 2; i <= n - 1; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    printf("Term %d in Fibonacci sequence: %d", n, b);
}