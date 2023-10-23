// Write a program to define a function that receives 5 integers and returns the sum (without using the return statement), average, and standard deviation of these numbers. Call this function from the main() and print the result in main().
#include <stdio.h>
#include <math.h>

void getStats(int n1, int n2, int n3, int n4, int n5, int *s, float *avg, float *std_dev)
{
    *s = n1 + n2 + n3 + n4 + n5;
    *avg = (float)*s / 5;

    float vari = 0;
    vari += pow(n1 - *avg, 2);
    vari += pow(n2 - *avg, 2);
    vari += pow(n3 - *avg, 2);
    vari += pow(n4 - *avg, 2);
    vari += pow(n5 - *avg, 2);
    vari /= 5;

    *std_dev = sqrt(vari);
}

int main()
{
    int num1, num2, num3, num4, num5, sum;
    float average, std_dev;

    printf("Enter five integers: ");
    scanf("%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5);

    getStats(num1, num2, num3, num4, num5, &sum, &average, &std_dev);

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Standard Deviation: %.2f\n", std_dev);
}