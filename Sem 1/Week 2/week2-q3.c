// Create a C program that calculates the compound interest on a principal amount given the interest rate and time period.
#include <stdio.h>
#include <math.h>

void main()
{
    float p, r, t, ci;
    printf("Enter the principal amount: ");
    scanf("%f", &p);
    printf("Enter the annual interest rate (as a decimal): ");
    scanf("%f", &r);
    printf("Enter the time period (in years): ");
    scanf("%f", &t);
    ci = p * pow(1 + r, t) - p;
    printf("Compound Interest: %.2f\n", ci);
}