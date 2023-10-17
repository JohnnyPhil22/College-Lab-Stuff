// Write a C program that converts a temperature in degrees Celsius to degrees Fahrenheit using the conversion formula.
#include <stdio.h>

void main()
{
    float c;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &c);
    printf("%f degrees Celsius = %f degrees Fahreheit", c, ((c * 1.8) + 32));
}