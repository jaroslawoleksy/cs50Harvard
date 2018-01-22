#include <stdio.h>
#include "helpers.h"

int main (void)
{
   int array[] = {4, 3, 2, 1, 9, 12, 33, 78};
   
   sort(array, 8);
   
   printf("[");
   for (int i = 0; i < 8; i++)
   {
       printf("%d ", array[i]);
   }
   printf("]\n");
   
   printf(search(78, array, 8) ? "true" : "false");
    
}