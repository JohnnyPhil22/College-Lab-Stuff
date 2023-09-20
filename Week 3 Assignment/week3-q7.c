// Compare three given numbers and print the largest number. (Using only one loop)
#include <stdio.h>

int main () {
    int a,b,c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a>b && a>c) {
        printf("%i is the largest number",a);
    } else if (b>c) {
        printf("%i is the largest number",b);
    } else {
        printf("%i is the largest number",c);
    }
}