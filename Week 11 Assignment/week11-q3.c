// There are five players from which the Most Valuable Player (MVP) is to be chosen. Each player is to be judged by 3 judges, who would assign a rank to each player. The player whose sum of ranks is highest is chosen as MVP. Write a C program to implement this scheme.
#include <stdio.h>

int main()
{
    int score1, score2, score3, players[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter scores for player %d (Judge 1, Judge 2, Judge 3): ", i + 1);
        scanf("%d %d %d", &score1, &score2, &score3);
        players[i] = score1 + score2 + score3;
    }
    int max = players[0], mvp = 0;

    for (int i = 1; i < 5; ++i)
    {
        if (players[i] > max)
        {
            max = players[i];
            mvp = i + 1;
        }
    }
    printf("MVP = Player %d, score = %d", mvp, max);
}