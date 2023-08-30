/*
// Print hello world
#include <stdio.h>

int main () {
    printf("Hello World\n");
}

// Check if year is leap year or not
#include <stdio.h>

int main () {
    int num;
    printf("Enter year: ");
    scanf("%d",&num);

    if (num%100==0) {
        if (num%400==0) {
            printf("Leap year\n");
        } else {
            printf("Not leap year\n");
        }
    } else {
        if (num%4==0) {
            printf("Leap year\n");
        } else {
            printf("Not leap year \n");
        }
    }
}

// Reverse inputted 5-digit number and check if it equal to original number (without loops)
#include <stdio.h>

int main () {
    int num,ori,rev=0,rem;
    printf("Enter number: ");
    scanf("%d",&num);
    ori=num;

    rem=num%10;
    rev=rev*10+rem;
    num/=10;
    rem=num%10;
    rev=rev*10+rem;
    num/=10;
    rem=num%10;
    rev=rev*10+rem;
    num/=10;
    rem=num%10;
    rev=rev*10+rem;
    num/=10;
    rem=num%10;
    rev=rev*10+rem;
    num/=10;
    printf("Reversed number: %i\n",rev);

    if (ori==rev) {
        printf("Reversed number is same as original number\n");
    } else {
        printf("Reversed number is not same as original number\n");
    }
}

// Youngest age among three people
#include <stdio.h>
int main () {
    int a,b,c;
    printf("Enter ages of three people: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a<b) {
        if (b<c) {
            printf("%i is the youngest age",a);
        } else {
            if (a<c) {
                printf("%i is the youngest age",a);
            } else {
                printf("%i is the youngest age",c);
            }
        }
    } else {
        if (b<c) {
            printf("%i is the youngest age",b);
        } else {
            printf("%i is the youngest age",c);
        }
    }
}

// Solve Q3 using conditional operators
#include <stdio.h>

int main () {
    int a,b,c;
    printf("Enter ages of three people: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a<b && a<c) {
        printf("%i is the youngest age",a);
    } else if (b<c) {
        printf("%i is the youngest age",b);
    } else {
        printf("%i is the youngest age",c);
    }
}

// Find whether year is leap year or not using && and ||.
#include <stdio.h>

int main () {
    int year;
    printf("Enter year: ");
    scanf("%d",&year);

    if (((year%100!=0) && (year%4==0)) || (year%400==0)) {
        printf("It is leap year");
    } else {
        printf("It is not leap year");
    }
}

// If it was Monday on 01/01/01, find out what day it is on 01/01/yy
#include<stdio.h>

int main () {
    int year, basic_year=1900, leap_year, remaining_year, total_days, day;

    printf("Enter the year: ");
    scanf("%d", &year);

    if (year<basic_year) {
        year = (basic_year-1)-year;
    } else {
        year = (year+1)-basic_year;
    }

    leap_year = year/4;

    remaining_year = year - leap_year;

    total_days = (remaining_year*365) + (leap_year*366) + 1;

    if(total_days%7==0) {
        printf("Monday");
    } else if(total_days%7==1) {
        printf("Tuesday");
    } else if(total_days%7==2) {
        printf("Wednesday");
    } else if(total_days%7==3) {
        printf("Thursday");
    } else if(total_days%7==4) {
        printf("Friday");
    } else if(total_days%7==5) {
        printf("Saturday");
    } else if(total_days%7==6) {
        printf("Sunday");
    }
}
*/