#include <stdio.h>
#include <cs50.h>
#include <string.h>

char uppercase(char alphabet);
int AssigningScore(int letter, int pointString[], int letterString[]);

int main(void)
{

    // initiallizing points
    int points[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // initializing alphabets
    int alphabets[26];
    alphabets[0] = 65;
    for (int i = 1; i < 26; i++)
    {
       
            alphabets[i] = alphabets[i - 1] + 1;
    }

    // take input from user 1 , 2 ;
    string Player1 = get_string("Player 1: ");
    string Player2 = get_string("Player 2: ");

    int lengthPlayer1 = strlen(Player1);
    int lengthPlayer2 = strlen(Player2);

    // convert to uppercase
    int player1Alpha[lengthPlayer1];
    int player2Alpha[lengthPlayer2];

    int player1Score = 0;
    int player2Score = 0;

    for (int i = 0; i < lengthPlayer1; i++)
    {
        player1Alpha[i] = uppercase(Player1[i]);
        if (player1Alpha[i] >= 65 && player1Alpha[i] <= 90)
        {
            // points assigning function
            player1Score = player1Score + AssigningScore(player1Alpha[i], points, alphabets);
        }
        else
        {
            player1Score = player1Score + 0;
        }
    }

    for (int i = 0; i < lengthPlayer2; i++)
    {
        player2Alpha[i] = uppercase(Player2[i]);
        if (player2Alpha[i] >= 65 && player2Alpha[i] <= 90)
        {
            // points assigning function
            player2Score = player2Score + AssigningScore(player2Alpha[i], points, alphabets);
        }
        else
        {
            player2Score = player2Score + 0;
        }
    }

    // conclusion to the game who win ;
    if (player1Score > player2Score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player2Score > player1Score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

char uppercase(char alphabet)
{
    if (alphabet >= 97 && alphabet <= 122)
    {
        return alphabet - 32;
    }
    else
    {
        return alphabet;
    }
}

int AssigningScore(int letter, int pointString[], int letterString[])
{
    for (int i = 0; i < 27; i++)
    {
        if (letter == letterString[i])
        {
            return pointString[i];
        }
    }
    return 0;
}