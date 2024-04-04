#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // declaring a variable so I can use it in a do/while loop
    int size;
    do
    {
        // using this statement and loop to handle user input and validation
        size = get_int("Height: ");
    }
    while (size < 1 || size > 8);

    // outer loop handles row counting
    for (int i = 1; i <= size; i++)
    {
        // first loop handles printing spaces
        for (int j = size; j > i; j--)
        {
            printf(" ");
        }
        // second loop handles printing hashes
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int m = 1; m <= i; m++)
        {
            printf("#");
        }
        // don't forget to go to the next line after printing spaces/hashes for a given row!
        printf("\n");
    }

    return 0;
}
