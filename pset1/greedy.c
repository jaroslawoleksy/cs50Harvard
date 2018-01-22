#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    float change;
    
    do
    {
        printf("O hai! How much change is owed?\n");
        change = GetFloat();
    }
    while (change < 0);
    
    int cents = roundf(change * 100);
    
    int quarters = 0;
    int dimes = 0;
    int nickles = 0;
    int pennies = 0;
    
    quarters = cents/25;
    cents = cents%25;
    dimes = cents/10;
    cents = cents%10;
    nickles = cents/5;
    cents = cents%5;
    pennies = cents;
    
    printf("%d\n", quarters + dimes + nickles + pennies);
    
}