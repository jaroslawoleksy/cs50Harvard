#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf("You should specify the encryption string.\n");
        return 1;
    }
    else
    {
        string k = argv[1];
        
        for (int j = 0, n = strlen(k); j < n; j++)
        {
            if (isalpha(k[j]) == false)
            {
                printf("The encryption string should contain letters only.\n");
                return 1;
            }
        }
        
        string plaintext = GetString();
        
        int currentKeywordKey = 0;
        
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            if (isalpha(plaintext[i]) == false)
            {
                printf("%c", plaintext[i]);
            }
            else
            {
                char kLetter = k[currentKeywordKey];
                int key;
                
                if (isupper(kLetter))
                {
                    key = (int)kLetter - 65;
                }
                else
                {
                    key = (int)kLetter - 97;
                }
                
                int newChar = (int)plaintext[i] + key;
                
                if (isupper(plaintext[i]) && newChar > 90)
                {
                    newChar = 65 + newChar - 91;
                }
                if (isupper(plaintext[i]) == false && newChar > 122)
                {
                    newChar = 97 + newChar - 123;
                }
                printf("%c", newChar);
                currentKeywordKey++;
                currentKeywordKey = currentKeywordKey%strlen(k);
            }
        }
        printf("\n");
        return 0;
    }
}