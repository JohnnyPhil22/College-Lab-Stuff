// Write a C program deal.c that deals a random hand from a standard deck of playing cards, i.e., we pick cards randomly from the deck and avoid picking the same card twice. We’ll have the user to specify how many cards should be in hand.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printRandomCard()
{
    char suits[] = {'c', 'd', 'h', 's'};
    char ranks[] = {'2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A'};

    char suit = suits[rand() % 4];
    char rank = ranks[rand() % 13];

    printf("(%c %c) ", rank, suit);
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

void main()
{
    srand((unsigned int)time(NULL));

    int numCards;
    printf("Enter the number of cards in hand: ");
    scanf("%d", &numCards);

    dealHand(numCards);
}
