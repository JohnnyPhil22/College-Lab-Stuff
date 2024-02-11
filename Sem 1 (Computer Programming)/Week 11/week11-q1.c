// Create a structure to specify data on students given below: Roll number, Name, Department, Course, Year of joining. Assume that there are not more than 450 students in the college. a) Write a function to print names of all students who joined in a particular year. b) Write a function to print the data of a student whose roll number is received by the function.
#include <stdio.h>

struct studata
{
    int rollno;
    char name[1000];
    char dept[1000];
    char cors[1000];
    int year;
};
struct studata studs[10];

void joinyrstuds(int yr, int size)
{
    int i;
    printf("Students from year %d\n", yr);
    for (i = 0; i < size; i++)
    {
        if (studs[i].year == yr)
        {
            printf("%s\n", studs[i].name);
        }
    }
}

void printdata(int rollno, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (studs[i].rollno == rollno)
        {
            printf("Roll No.: %d\nName: %s\nDepartment: %s\nCourse: %s\nYear of Joining: %d\n", studs[i].rollno, studs[i].name, studs[i].dept, studs[i].cors, studs[i].year);
        }
    }
}

int main()
{
    int i, size, year, rollno;
    printf("Enter number of students: ");
    scanf("%d", &size);
    printf("Enter Records of %i students\n", size);
    for (i = 0; i < size; i++)
    {
        printf("Enter Roll No.: ");
        scanf("%d", &studs[i].rollno);
        printf("Enter Name: ");
        scanf("%s", &studs[i].name);
        printf("Enter Department: ");
        scanf("%s", &studs[i].dept);
        printf("Enter Course: ");
        scanf("%s", &studs[i].cors);
        printf("Enter Year of Joining: ");
        scanf("%d", &studs[i].year);
    }

    printf("Enter year to print student names: ");
    scanf("%d", &year);
    joinyrstuds(year, size);

    printf("Enter roll number to print student details: ");
    scanf("%d", &rollno);
    printdata(rollno, size);
}