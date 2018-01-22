#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    string name = GetString();
    bool firstLetterFound = false;
    bool setInitial = true;
    
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        if (name[i] == ' ')
        {
            if (firstLetterFound == false)
            {
                printf(" ");
            }
            else
            {
                setInitial = true;
            }
        }
        else
        {
            if (setInitial)
            {
                printf("%c", toupper(name[i]));
                firstLetterFound = true;
                setInitial = false;
            }
            
        }
    }
    printf("\n");
}