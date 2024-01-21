#include<cs50.h>
#include <stdio.h>
#include <string.h>

string validator(string number);

int main(void)
{
    string cardno = get_string("Card #: ");

    string type = validator(cardno);
    printf("%s", type);

    return 0;
}

string validator(string number)
{
    string type = "";
    int cleanmod_sum = 0;
    int mod_sum = 0;
    int product = 0;
    int total_sum = cleanmod_sum + mod_sum;

    for(int i = strlen(number) - 1; i > 0; i--)
    {
        int digi_char = (int)number[i] - '0';

        if (i % 2 == 0)
        {
            mod_sum += digi_char;
        }
        else
        {
            cleanmod_sum += digi_char*2;
        }
    }
    if(total_sum % 10 != 0)
    {
        type = "INVALID\n";
    }
    else
    {
        if((int)number[0]-'0' == 4)
        {
            type = "VISA\n";
        }
        else if((int)number[0]-'0' == 3 && ((int)number[1]-'0' == 4 || (int)number[1]-'0' == 7))
        {
            type = "AMEX\n";
        }
        else if((int)number[0]-'0' == 5 && ((int)number[1]-'0' == 1 || (int)number[1]-'0' == 2 || (int)number[1]-'0' == 3 || (int)number[1]-'0' == 4 || (int)number[1]-'0' == 5))
        {
            type = "MC\n";
        }
        else
        {
            type = "CARD IS VALID BUT TYPE UNKNOWN\n";
        }
    }
    return type;
}
