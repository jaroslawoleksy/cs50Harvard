#include <stdio.h>
#include <string.h>

char password[8] = " ";

int main (void)
{
    void nextPassword (void);
    
    for (int i = 32; i <= 20000; i++)
    {
        printf("%s\n", password);
        nextPassword();
    }
        
}

void nextPassword (void)
{
    int passLen = strlen(password);
    int index = passLen - 1;
    
    if (password[index] != (char)126)
    {
        password[index]++;
    }
    else
    {
        while (index >= 0 && password[index] == (char)126)
        {
            index--;

        }
        int startIndex;
        
        if (index >=0)
        {
            startIndex = passLen - 1;
            password[index]++;
        }
        else
        {
            startIndex = passLen;
        }
        
        
        for (int i = startIndex; i > index; i--)
        {
            printf("Password to change: %s, i: %d\n", password, i);
            password[i] = (char)32;
        }
        
        
        
            
        
    }
}