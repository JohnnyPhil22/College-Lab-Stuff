// Compare three given numbers and print the largest number, second largest and smallest number. (do not use loop)
#include <stdio.h>

int main () {
    int a,b,c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a>b && a>c) {
        if (b>c) {
            printf("Order: %i\n       %i\n       %i",a,b,c);
        } else {
            printf("Order: %i\n       %i\n       %i",a,c,b);
        }
    } else if (b>a && b>c) {
        if (a>c) {
            printf("Order: %i\n       %i\n       %i",b,a,c);
        } else {
            printf("Order: %i\n       %i\n       %i",b,c,a);
        }
    } else if (c>a && c>b) {
        if (a>b) {
            printf("Order: %i\n       %i\n       %i",c,a,b);
        } else {
            printf("Order: %i\n       %i\n       %i",c,b,a);
        }
    }
}