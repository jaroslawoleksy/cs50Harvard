/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 #include <stdio.h>
 #include <stdlib.h>

int main(void)
{
    FILE* card = fopen("card.raw", "r");
    if (card == NULL)
    {
        printf("Couldn't open card.raw\n");
        return 1;
    }
    
    char title[8];
    unsigned char block[512];
    FILE* img;
    int number = 0;

    while (fread(&block, 512, 1, card) != 0)
    {
        
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && block[3] >= 0xe0 && block[3] <= 0xef)
        {
            if (number > 0)
            {
                fclose(img);
            }
            
            sprintf(title, "%03d.jpg", number);
            
            number++;
            img = fopen(title, "w");
        }
        
        if (number > 0)
        {
            fwrite(&block, 512, 1, img);
        }
        
    }
    
    
    
    fclose(img);
    fclose(card);
    
    
    return 0;
}
