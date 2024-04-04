#include <cs50.h>
#include <stdio.h>

int main(void)
{
  string name = get_string("What's your name? ");
  printf("Hello there, %s\n", name);

  return 0;
}

