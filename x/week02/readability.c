#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
   string text = get_string("Text: ");
   int length = strlen(text);
   int sentences = 0;
   int words = 0;
   int letters = 0;

   for(int i = 0; i < length; i++)
   {
      if(text[i] == '.' || text[i] == '!' || text[i] == '?')
      {
         sentences++;
      }
      if(text[i] == ' ')
      {
         words++;
      }
      if ( isalnum( ( unsigned char )text[i] ) )
      {
         letters++;
      }
   }

   float L = ((float)letters / (float)words) * 100;
    float S = ((float)sentences / (float)words) * 100;
    float coleman = 0.0588 * L - 0.296 * S - 15.8;
    int index = round(coleman);
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade reading level:  %i\n", index);
    }

   return 0;
}
