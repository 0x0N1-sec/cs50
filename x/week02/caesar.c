#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


char rotate(char s, int k);

int main(int argc, string argv[])
{
    // check if they input a string
    if (argc == 2)
    {
        //checks if each char is a digit
        for (int i = 0; i < strlen(argv[1]); i++)

            if(isdigit(argv[1][i]) == false)
            {
                 printf("Usage: ./caesar key");
                return 1;
             }
    }
    else
    {
        printf("Usage: ./caesar key");
        return 1;
    }



    //convert to int
    int key_int = atoi(argv[1]);


    //get plaintext
    string plaintext = get_string("enter message: ");

    //encrypt
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        rotate(plaintext[i], key_int);
    }
    printf("\n");


}


//rotates a char by the amount given in the key
char rotate(char c, int k)
{
    // checks if its a letter
    if (isalpha(c))
    {
        // if it's uppercase
        if (isupper(c))
        {
            c = c - 65 + k;
            c = c % 26 + 65;
        }
        // if its lowercase
        else
        {
            c = c - 97 + k;
            c = c % 26 + 97;

        }
        printf("%c", c);
    }
    // not alphabetical characters don't get changed (1,?,.):
    else
    {
        printf("%c", c);
    }
    return c;
}
