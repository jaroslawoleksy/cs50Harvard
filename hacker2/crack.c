#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

char createdPassword[8] = " ";

int main (int argc, string argv[])
{
    void nextPassword (void);
    
    if (argc !=2)
    {
        printf("Only one password is accepted.\n");
        return 1;
    }
    else
    {
        
        char line[] = "";
        string password;
        char salt[] = "..";
        string passwordToCheck = argv[1];
        salt[0] = passwordToCheck[0];
        salt[1] = passwordToCheck[1];
       
        // check the words directory for the password
        FILE *myFile;
        
        if ((myFile = fopen("words", "r")) == NULL)
        {
            printf("Error opening the words file.\n");
            return 1;
        }
        
        while (fgets(line, 25, myFile) != NULL)
        {
            line[strlen(line) - 1] = '\0'; // to change the \n from the string in the words file
            
            password = crypt(line, salt);
            
            if (strncmp(password, passwordToCheck, 56) == 0)
            {
                printf("%s\n", line);
                return 0;
            }
        }
        fclose(myFile);
                
        // check all the possible words for password
        while (strncmp(createdPassword, "~~~~~~~~", 56) != 0) // the program shoul only checkk for the 8 char passwords
        {
            nextPassword();
            password = crypt(createdPassword, salt);
            //printf("Password: %s, createdPassword: %s, salt: %s\n", password, createdPassword, salt);
            if (strncmp(password, passwordToCheck, 56) == 0)
                {
                    printf("%s\n", createdPassword);
                    return 0;
                }
        }
    }
   
   
}


// a function to create the next possible password
// out of the available ascii chars
void nextPassword (void)
{
    // leght of the current password
    int passLen = strlen(createdPassword);
    
    // index to check for the chars in the password
    int index = passLen - 1;
    
    if (createdPassword[index] != (char)126) // if the last char in the password is not ~
    {
        createdPassword[index]++;            // then pick the next char for it

    }
    else
    {
        // loop to check how many tildas (~) are at the end of the password
        while (index >= 0 && createdPassword[index] == (char)126)
        {
            index--;

        }
        
        // the index that indicates whether the code should increase
        // the number of chars in the password (if the password consists
        // only with tildas - ~~~~~)
        int startIndex;
        
        // the if statement to check if all the chars in the password are ~
        if (index >= 0) // not all the chars are ~
        {
            startIndex = passLen - 1;
            createdPassword[index]++;       // increase the first char before ~s
        }
        else
        {
            startIndex = passLen;
        }
        
        // the loop to insert " " after the first char
        for (int i = startIndex; i > index; i--)
        {
            createdPassword[i] = (char)32;
        }
            
    }
    
}