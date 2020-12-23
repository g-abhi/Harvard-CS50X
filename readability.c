#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float count_letters(string s);

float count_words(string s);

float count_sentences(string s);

void determineGradeLevel(float numLetters, float numWords, float numSentences);

//executing the main method with received input from user
int main(void)
{
    //receive user input
    string s = get_string("Text: ");
    
    //establish values for variables
    float num_letters = count_letters(s);
    float num_words = count_words(s);
    float num_sentences = count_sentences(s);
    
    //test prints
    //printf("%i letter(s)\n", num_letters);
    //printf("%i word(s)\n", num_words);
    //printf("%i sentence(s)\n", num_sentences);
    
    //final output
    determineGradeLevel(num_letters, num_words, num_sentences);
    
}

//helper method to count letters
float count_letters(string s)
{
    float counter = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            counter++;
        }
    }
    return counter;
}

//helper method to count words
float count_words(string s)
{
    float counter = 1;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            counter++;
        }
    }
    return counter;
}

//helper method to count sentences
float count_sentences(string s)
{
    float counter = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if ((s[i] == '.') || (s[i] == '!') || (s[i] == '?'))
        {
            if (i != strlen(s) - 1)
            {
                if (s[i + 1] == ' ')
                {
                    counter++;
                }
            }
            else
            {
                counter++;
            }
            
        }
    }
    return counter;
}

//helper method to determine grade level
void determineGradeLevel(float numLetters, float numWords, float numSentences)
{
    float L = numLetters / numWords * 100.0;
    float S = numSentences / numWords * 100.0;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    //printf("%f\n", index);
    int grade_level = round(index);
    
    if (grade_level <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else 
    {
        printf("Grade %i\n", grade_level);
    }
}