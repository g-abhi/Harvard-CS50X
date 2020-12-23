#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    //receive user input
    float dollars_input = 0.0;
    do
    {
        dollars_input = get_float("Enter your input:");
    }
    while (dollars_input < 0);

    //convert input dollar value to cents
    int cents_value = round(dollars_input * 100);
    //test calculation
    //printf("%i\n", cents_value);

    //calculate number of required coins
    int counter = 0;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    if (cents_value >= quarter)
    {
        counter += cents_value / quarter;
        cents_value %= quarter;
    }
    if (cents_value >= dime)
    {
        counter += cents_value / dime;
        cents_value %= dime;
    }
    if (cents_value >= nickel)
    {
        counter += cents_value / nickel;
        cents_value %= nickel;
    }
    if (cents_value >= penny)
    {
        counter += cents_value / penny;
        cents_value %= penny;
    }
    printf("%i\n", counter);
}
