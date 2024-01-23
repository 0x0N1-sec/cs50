#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define ULEN 26

string scrabbler(string oneWord, string twoWord);

int main(int argc, string argv[])
{
    string oneWord = get_string("Player 1: ");
    string twoWord = get_string("Player 2: ");

    string result = scrabbler(oneWord, twoWord);
    printf("%s\n", result);

    return 0;
}

string scrabbler(string oneWord, string twoWord)
{
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int points[26] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};

    int onePoints = 0;
    int twoPoints = 0;

    int oneLength = strlen(oneWord);
    int twoLength = strlen(twoWord);

    for(int i = 0; i < oneLength; i++)
    {
        for(int j = 0; j < ULEN; j++)
        {
            if(oneWord[i] == asciiBet[j])
            {
                onePoints += points[j];
                break;
            }
        }
    }
    for(int i = 0; i < twoLength; i++)
    {
        for(int j = 0; j < ULEN; j++)
        {
            if(twoWord[i] == asciiBet[j])
            {
                twoPoints += points[j];
                break;
            }
        }
    }
    if(onePoints > twoPoints)
    {
        return "Player 1 Wins!";
    }
    else if(twoPoints > onePoints)
    {
        return "Player 2 Wins!";
    }
    else
    {
        return "Tie!";
    }
}
