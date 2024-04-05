#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // Using a for loop to go from 2 to 'number' non-inclusive
    for (int i = 2; i < number; i++)
    {
        // if we find a factor of 'number' we know 'number'
        // is not prime so we go ahead and return false.
        if (number % i == 0)
        {
            return false;
        }
    }
    // if false is never returned then the number must be prime
    return true;
}
