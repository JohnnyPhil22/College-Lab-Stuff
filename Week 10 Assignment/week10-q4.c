// Modify the deal.c program of Q.No. 6 so that it prints the full names of the cards it deals
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printRandomCard()
{
    char *suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    char *ranks[] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};

    char *suit = suits[rand() % 4];
    char *rank = ranks[rand() % 13];

    printf("(%s of %s) ", rank, suit);
}

void dealHand(int numCards)
{
    printf("Randomly dealt hand with %d cards:\n", numCards);

    for (int i = 0; i < numCards; ++i)
    {
        printRandomCard();
    }

    printf("\n");
}

int main()
{
    srand((unsigned int)time(NULL));

    int numCards;
    printf("Enter the number of cards in hand: ");
    scanf("%d", &numCards);

    dealHand(numCards);

    return 0;
}
