#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

//helper methods
string shiftCapitalLetters(string s, int key);
string shiftLowercaseLetters(string s, int key);

//executing the main method with received input from user
int main(int argc, string argv[])
{
    //verify user commandline arguments
    int key = 0;
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }
    else
    {
        string userInput = argv[1];
        // printf("%i\n", key);
        int counter = 0;
        for (int i = 0; i < strlen(userInput); i++)
        {
            if (userInput[i] >= '0' && userInput[i] <= '9')
            {
                counter++;
            }
        }
        
        if (counter == strlen(userInput))
        {
            key = atoi(userInput);
            printf("Success\n");
        }
        else
        {
            printf("Usage: ./caesar key\n");
            exit(1);
        }
    }
    
    //test print statements
    //char c = ('Z' + key - 65) % 26 + 65;
    //printf("%c\n", c);
    
    //receive user input for plaintext
    string s = get_string("plaintext: ");
    
    //perform caesar shift and print ciphertext
    string str_shiftedUppercase = shiftCapitalLetters(s, key);
    string str = shiftLowercaseLetters(str_shiftedUppercase, key);
    printf("ciphertext: %s\n", str);
}

//helper method to shift uppercase letters
string shiftCapitalLetters(string s, int key)
{
    char c = ' ';
    string str = "";
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            c = (s[i] + key - 65) % 26 + 65;
            s[i] = c;
        }
    }
    return s;
}

//helper method to shift lowercase letters
string shiftLowercaseLetters(string s, int key)
{
    char c = ' ';
    string str = "";
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            c = (s[i] + key - 97) % 26 + 97;
            s[i] = c;
        }
    }
    return s;
}