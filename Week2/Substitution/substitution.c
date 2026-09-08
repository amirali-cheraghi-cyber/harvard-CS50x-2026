#include <cs50.h>
#include <stdio.h>
#include <string.h>

int check_key(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (check_key(argv[1]) == 1)
    {
        return 1;
    }

    string text = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(text); i++)
    {
        char c = text[i];

        if (c >= 'a' && c <= 'z')
        {
            int index = c - 'a';
            char encrypted = argv[1][index];

            if (encrypted >= 'A' && encrypted <= 'Z')
            {
                encrypted = encrypted + 32;
            }

            printf("%c", encrypted);
        }
        else if (c >= 'A' && c <= 'Z')
        {
            int index = c - 'A';
            char encrypted = argv[1][index];

            if (encrypted >= 'a' && encrypted <= 'z')
            {
                encrypted = encrypted - 32;
            }

            printf("%c", encrypted);
        }
        else
        {
            printf("%c", c);
        }
    }

    printf("\n");
    return 0;
}

int check_key(string key)
{
    int len = strlen(key);

    if (len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < len; i++)
    {
        char c = key[i];

        if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z'))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }

    for (int i = 0; i < len; i++)
    {
        char c1 = key[i];

        if (c1 >= 'a' && c1 <= 'z')
        {
            c1 = c1 - 32;
        }

        for (int j = i + 1; j < len; j++)
        {
            char c2 = key[j];

            if (c2 >= 'a' && c2 <= 'z')
            {
                c2 = c2 - 32;
            }

            if (c1 == c2)
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    return 0;
}
