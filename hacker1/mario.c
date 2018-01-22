#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int height;
    do
    {
        printf("Height: ");
        height = GetInt();
    }
    while (height < 0 || height > 23);
    
    for (int row = 1; row <= height; row++)
    {
        
        /*
        for (int space = 1; space <= height * 2 + 2; space++)
        {
            if (space <= height - row || ((space <= height + 2) && (space > height)) || (space > height + 2 + row))
            {
                printf(" ");
            }
            else
            printf("#");
        }
        */
        
        for (int space = 1; space <= height; space++)
        {
            if (space > height - row)
            {
                printf("#");
            }
            else printf(" ");
        }
        
        printf("  ");
        
        for (int space = 1; space <= row; space++)
        {
            printf("#");
        }
        
        printf("\n");
    }
    
}