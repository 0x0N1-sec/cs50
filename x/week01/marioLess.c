#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("How high should our pyramid be? ");

    for(int i = 0; i < height; i++)
    {
        for(int j = height; j > i+1; j--)
        {
            printf(" ");
        }
        for(int k = 0; k < i+1; k++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
