#include <stdio.h>
#include <cs50.h>

//executing the main method with received input from user
int main(void)
{
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
}
