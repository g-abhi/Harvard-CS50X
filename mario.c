#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int num = 0;

    //do while loop
    do
    {
        num = get_int("Enter a positive integer between 1 and 8, inclusive:");
    }
    while (num < 1 || num > 8);

    //for loops for printing
    for (int i = 0; i < num; i++)
    {
        for (int j = (num - i - 1); j > 0; j--)
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
    
    
}
