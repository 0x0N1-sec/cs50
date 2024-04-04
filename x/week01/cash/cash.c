#include <cs50.h>
#include <stdio.h>

#define QTR 25
#define DIM 10
#define NKL 5
#define PNY 1

int makeChange(int amt);

int main(void)
{
    // go ahead and initialize a variable to use for input
    int change = 0;
    do
    {
        // using a do/while loop + below statement to get/validate input
        change = get_int("Change owed: ");
    }
    while (change < 1);

    // printing the results and calling the function directly in print function
    printf("%d\n", makeChange(change));

    return 0;
}

int makeChange(int amt)
{
    // setting up a tmp var to keep original secure
    // also setting up a count var to return once done running over change owed
    int tmpAmt = amt;
    int count = 0;

    // going through amount via while loop and subtracting coin values from them
    // as they are matched with remaining amounts, keepin' it greedy!
    while (tmpAmt > 0)
    {
        if (tmpAmt >= 25)
        {
            tmpAmt -= 25;
            count++;
        }
        else if (tmpAmt >= 10)
        {
            tmpAmt -= 10;
            count++;
        }
        else if (tmpAmt >= 5)
        {
            tmpAmt -= 5;
            count++;
        }
        else
        {
            tmpAmt -= 1;
            count++;
        }
    }
    // returning final coin count
    return count;
}
