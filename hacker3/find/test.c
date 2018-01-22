#include <stdio.h>
#include <cs50.h>

#include "helpers.h"
const int MAX = 65536;


int main (void)
{
    //void sort(int values[], int n);
    int a = 10;
    int array[10] = {3, 2, 1, 50000, 49, 1, 2, 3, 10, 52000};
    
    sort(array, a);
    
    for (int i = 0; i < a; i++)
    {
        printf("%d ", array[i]);
    }
    
}
/*
void sort(int values[], int n)
{
    int valCount[MAX];
    int counter = 0;
    
    for (int i = 0; i < n; i++)
    {
        valCount[values[i]]++;
    }
    
    for (int j = 0; j < n; j++)
    {
        int reps = valCount[j];
        for (int k = 0; k < reps; k++)
        {
            values[counter] = j;
            counter ++;
        }
    }
    return;
}
*/