// WAP to print all ASCII values and their equivalent characters.
#include <stdio.h>
int main()
{
    int k;
    for (k = 0; k <= 255; k++)
    {
        printf("ASCII Value of %c is %d\n", k, k);
    }
}