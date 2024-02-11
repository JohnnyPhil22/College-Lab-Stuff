// Implement the following programs using recursion.
/// a. Factorial
#include <stdio.h>
int fact(int num)
{
    int sum = 1;
    if (num == 0)
    {
        sum *= 1;
    }
    else
    {
        sum = num * fact(num - 1);
    }
    return sum;
}
void main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("Factorial of %d: %d\n", n, fact(n));
}
/// b. Fibonacci Series
#include <stdio.h>
int fibon(int num)
{
    if (num == 0)
    {
        return 0;
    }
    else if (num == 1)
    {
        return 1;
    }
    else
    {
        return fibon(num - 1) + fibon(num - 2);
    }
}
void main()
{
    int n, i;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", fibon(i));
    }
    printf("\n");
}
/// c. Greatest Common Divisor
#include <stdio.h>
int gcd(int x, int y)
{
    if (y == x)
    {
        return x;
    }
    gcd((x < y ? x : y), (y > x ? y - x : x - y));
}
void main()
{
    int n1, n2;
    printf("Enter a and b: ");
    scanf("%d %d", &n1, &n2);
    printf("GCD of %d and %d: %d\n", n1, n2, gcd(n1, n2));
}
/// d. Tower of Hanoi
#include <stdio.h>
void towers(int num, char from, char to, char aux)
{
    if (num == 1)
    {
        printf("\n Move disk 1 from peg %c to peg %c", from, to);
        return;
    }
    towers(num - 1, from, aux, to);
    printf("\n Move disk %d from peg %c to peg %c", num, from, to);
    towers(num - 1, aux, to, from);
}
int main()
{
    int n;
    printf("Enter the number of disks : ");
    scanf("%d", &n);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(n, 'A', 'C', 'B');
}