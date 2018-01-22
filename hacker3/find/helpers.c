/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

bool binarySearch(int value, int values[], int from, int to);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int array[], int n)
{
    return binarySearch(value, values, 0, n - 1);
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int *valCount = calloc(65536, sizeof(int));
    int index = 0;
    int maxValue = 0;
    
    for (int i = 0; i < n; i++)
    {
        valCount[values[i]]++;
        if (values[i] > maxValue)
        {
            maxValue = values[i];
        }
        
    }
    
    for (int counter = 0; counter < maxValue + 1; counter++)
    {
        
        while (valCount[counter] > 0)
        {
            values[index] = counter;
            index++;
            valCount[counter]--;
        }
    }
    return;
}

bool binarySearch(int value, int values[], int from, int to)
{
    if ((to - from) == 0)
    {
        if (value == values[to])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    int midIndex = from + (to - from) / 2;
    
    if (value == values[midIndex])
    {
        return true;
    }
    else if (value > values[midIndex])
    {
        from = midIndex + 1;
    }
    else
    {
        to = midIndex - 1;
    }
    return binarySearch(value, values, from, to);
}