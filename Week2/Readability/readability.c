#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = (float)letters / words * 100.0;
    float S = (float)sentences / words * 100.0;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }

    return 0;
}

int count_letters(string text)
{
    int total = 0;
    int len = strlen(text);

    for (int i = 0; i < len; i++)
    {
        char c = text[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            total = total + 1;
        }
    }

    return total;
}

int count_words(string text)
{
    int total = 0;
    int len = strlen(text);
    int in_word = 0;

    for (int i = 0; i < len; i++)
    {
        char c = text[i];

        if (c == ' ' || c == '\n' || c == '\t')
        {
            in_word = 0;
        }
        else if (in_word == 0)
        {
            total = total + 1;
            in_word = 1;
        }
    }

    return total;
}

int count_sentences(string text)
{
    int total = 0;
    int len = strlen(text);

    for (int i = 0; i < len; i++)
    {
        char c = text[i];

        if (c == '.' || c == '?' || c == '!')
        {
            total = total + 1;
        }
    }

    return total;
}
