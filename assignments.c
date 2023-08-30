// Reverse number (using loops)
#include <stdio.h>

int main () {
    int num,rev=0,rem;
    printf("Enter number: ");
    scanf("%d",&num);

    while (num!=0) {
        rem=num%10;
        rev=rev*10+rem;
        num/=10;
    }
    
    printf("Reversed number: %i\n",rev);
}

// Find out if number is prime number or not
#include <stdio.h>

int main() {
    int num,i,flag=0;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    
    if (num==0||num==1) {
        flag=1;
    }
    
    for (i=2;i<=num/2;i++) {
        if (num%i==0) {
            flag=1;
            break;
        }
    }
    
    if (flag==0) {
        printf("%d is a prime number.",num);
    } else {
        printf("%d is not a prime number.",num);
    }
}