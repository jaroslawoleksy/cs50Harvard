#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void) 
{
    int even = 1;
    printf("Number: ");
    long long int card_number = GetLongLong();
    
    int checksum = 0;
    int sum = 0;
    int card_type = 0;
    long long int current_cn = card_number;
    int digits = 1;
    string card = "INVALID";
    
    do
    {
        sum = current_cn%10 * even;
        even = (even == 1) ? 2 : 1;
        
        sum =  (sum / 10 > 0) ? sum%10 + 1 : sum;

        checksum = checksum + sum;
       
        current_cn /= 10;
        
        /* AMERICAN EXPRESS */
        if ((current_cn == 34 || current_cn == 37) && (digits == 13))
        {
            card_type = 1;
            card = "AMEX";
        }
        /* MASTERCARD */
        if (current_cn >= 51 && current_cn <=55 && (digits == 14))
        {
            card_type = 2;
            card = "MASTERCARD";
        }
        /* VISA */
        if (current_cn == 4 && (digits == 12 || digits == 15))
        {
            card_type = 3;
            card = "VISA";
        }
        
        digits++;

    }
    while (current_cn > 0);
    
    if (checksum%10 == 0)
    {
        printf("%s\n", card);
        /*
        switch (card_type)
        {
            case 0:
                printf("INVALID\n");
                break;
                
            case 1:
                printf("AMEX\n");
                break;
                
            case 2:
                printf("MASTERCARD\n");
                break;
            
            case 3:
                printf("VISA\n");
                break;
        }
        */
    } else
        printf("INVALID\n");
    
}
