#include <stdio.h>
#include <cs50.h>

int main (void) 
{
    int height;
    do
    {
        printf("height: ");
        height = GetInt();
        
    } while (height < 0 || height > 23);
    
    for (int row = 1; row <= height; row++) 
    {
        for (int space = 0; space < height; space++)
        {
            if (space < height - row)
            {
                printf(" ");
            } else
            {
                printf("#");
            }
        }
        printf("#\n");
    }
}
