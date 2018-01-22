#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int height = 0;
    int row = 0;
    int spaces = 0;
    int hashes = 0;
    
    do {
        printf("height: ");
        height = GetInt();
    }
    while (height < 0 || height > 23);
    
    /*
    for (row = 1; row < height; row++)
    */
    for (row = 1; row <= height; row++)
    {
        /*
        for (spaces = (height - row); spaces >= 0; spaces--)
        */
        for (spaces = (height - row); spaces > 0; spaces--)
        {
            printf(" ");
        }
        /*
        for (hashes = 0; hashes <= row + 1 ; hashes++)
        */
        for (hashes = 1; hashes <= row + 1; hashes++)
        {
            printf("#");
        }
        /*
        printf(".\n");
        */
        printf("\n");
    }
    
}