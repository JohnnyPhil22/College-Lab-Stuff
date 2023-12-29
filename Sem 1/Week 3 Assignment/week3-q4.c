// Print grade of a student according to the score, where A+ for 85 or above, A for 75 to 84, B+ for 65 to 74, B for 50 to 64, C for 30 to 49 and fail below 30.
#include <stdio.h>
int main()
{
    int marks;
    printf("Enter marks: ");
    scanf("%d", &marks);

    if (marks >= 85)
    {
        printf("Grade: A+\n");
    }
    else if (75 <= marks && marks <= 84)
    {
        printf("Grade: A\n");
    }
    else if (65 <= marks && marks <= 74)
    {
        printf("Grade: B+\n");
    }
    else if (50 <= marks && marks <= 64)
    {
        printf("Grade: B\n");
    }
    else if (30 <= marks && marks <= 49)
    {
        printf("Grade: C\n");
    }
    else if (marks < 30)
    {
        printf("Failed\n");
    }
    else
    {
        printf("Enter valid marks\n");
    }
}