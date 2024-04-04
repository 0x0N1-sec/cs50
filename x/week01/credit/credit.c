// test with: 4003600000000014
// test with: 6176292929
// test with: 3782822463100051
// COME BACK AND FIX THIS COMPLETELY!! THIS STR APPROACH ISN'T WORKING!!
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string numCheck(string ccn);

int main(void)
{
    char *ccNum;

    printf("Number: ");
    scanf("%ms", &ccNum);

    printf("%s\n", numCheck(ccNum));

    free(ccNum);

    return 0;
}

string numCheck(string ccn)
{
    string cardType = "INVALID";
    int sum1 = 0;
    int sum2 = 0;
    int placeCounter1 = strlen(ccn) - 2;
    int placeCounter2 = strlen(ccn) - 1;

    // VISA if 13 or 16 Digits + Starts with 4
    if (ccn[0] - '0' == 4 && (strlen(ccn) == 16 || strlen(ccn) == 13))
    {
        cardType = "VISA";
    }
    // MASTERCARD if 16 Digits + Starts with 51, 52, 53, 54, 55
    else if (ccn[0] - '0' == 5 && strlen(ccn) == 16)
    {
        if (ccn[1] - '0' == 1 || ccn[1] - '0' == 2 || ccn[1] - '0' == 3 || ccn[1] - '0' == 4 ||
            ccn[1] - '0' == 5)
        {
            cardType = "MASTERCARD";
        }
    }
    // AMEX if 15 Digits + Starts with 34, 37
    else if (ccn[0] - '0' == 3 && strlen(ccn) == 15)
    {
        if (ccn[1] - '0' == 7 || ccn[1] - '0' == 4)
        {
            cardType = "AMEX";
        }
    }

    while (placeCounter1 >= 0)
    {
        // this really threw me for a loop for a bit
        // I was adding the products and not the digits!
        // Watch out for that!!!
        if (((ccn[placeCounter1] - '0') * 2) >= 10)
        {
            // use division/mod to separate values 10-18 (18 is highest possible)
            int tens = ((ccn[placeCounter1] - '0') * 2) / 10;
            int modPart = ((ccn[placeCounter1] - '0') * 2) % 10;
            sum1 += tens;
            sum1 += modPart;
        }
        else
        {
            // this one requires nothing fancy as no breaking apart
            // of digits is required
            sum1 += (ccn[placeCounter1] - '0') * 2;
        }
        placeCounter1 -= 2;
    }

    // this one also requires nothing fancy as we don't have
    // any products being calculated, the highest possible value is 9
    while (placeCounter2 >= 0)
    {
        sum2 += (ccn[placeCounter2] - '0');
        placeCounter2 -= 2;
    }
    int total = sum1 + sum2;
    if (total % 10 != 0)
    {
        cardType = "INVALID";
    }
    return cardType;
}