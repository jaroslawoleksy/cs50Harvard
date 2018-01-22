#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf("You should specify the key encryption value.\n");
        return 1;
    }
    else
    {
        int key = atoi(argv[1]);
        key = key%26;
        string plaintext = GetString();
        
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            if (isalpha(plaintext[i]) == false)
            {
                printf("%c", plaintext[i]);
            }
            else
            {
                int newChar = (int)plaintext[i] - key;
                
                if (isupper(plaintext[i]) && newChar < 65)
                {
                    newChar = 90 + newChar - 64;
                }
                if (isupper(plaintext[i]) == false && newChar < 97)
                {
                    newChar = 122 + newChar - 96;
                }
                printf("%c", newChar);
            }
        }
        printf("\n");
        return 0;
    }
}