#include <cs50.h>
#include <stdio.h>

#define QTR 25
#define DIM 10
#define NIC 5
#define PEN 1

int coinCounter(int amount);

int main(void)
{
    int totalMoney = get_int("How much change is owed (in cents): ");
    int coinReturn = coinCounter(totalMoney);
    printf("\nCoins: %i\n", coinReturn);


    return 0;
}

int coinCounter(int amount)
{
    int runningAmt = amount;
    int coins = 0;

    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;

    while(runningAmt >0)
    {
        if (runningAmt >= QTR)
        {
            quarters++;
            runningAmt -= QTR;
        }
        else if (runningAmt >= DIM)
        {
            dimes++;
            runningAmt -= DIM;
        }
        else if (runningAmt >= NIC)
        {
            nickels++;
            runningAmt -= NIC;
        }
        else if (runningAmt >= PEN)
        {
            pennies++;
            runningAmt -= PEN;
        }
    }
    coins = quarters + dimes + nickels + pennies;
    return coins;
}
