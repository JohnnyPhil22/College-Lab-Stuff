/*
Tower of Hanoi is a mathematical puzzle where we have three pegs (A, B, and C) and N disks. Initially, all the disks are stacked in decreasing value of diameter i.e., the smallest disk is placed on the top and they are on peg A. The objective of the puzzle is to move the entire stack to another peg (here considered C), obeying the following simple rules:
·    Only one disk can be moved at a time.
·    Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
·    No disk may be placed on top of a smaller disk.
Write a C function that demonstrates the recursive solution of the aforesaid problem.
*/
#include <stdio.h>

void towerOfHanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    towerOfHanoi(n - 1, aux, to, from);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'C', 'B');
}