#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void nextPositions();
bool moveBlank(int array[], int dim, char direction);
int findBlank(int array[], int n);
int manhattanDistance(int array[], int dim);
void switchValues (int array[], int index1, int index2);
void draw(int array[]);
void changeArraySize (int*** array, int len);
void freeArray (int*** array, int len);


int currentPos[2][9] = {{2, 3, 4, 5, 1, 0, 6, 8, 7}, {0, 0, 1}}; // {{puzzle sequence}, {current cost, ManhattanDistance, isItOpen}
int ***openList;
int openListLen = 0;

int main (void)
{
    openListLen = 1;
    openList = (int***) malloc((openListLen) * sizeof(int**));
    
    for (int i = 0; i < openListLen; i++)
    {
        openList[i] = (int**) malloc(2 * sizeof(int*));
        for (int j = 0; j < 2; j ++)
        {
            openList[i][j] = (int*) malloc(9 * sizeof(int));
        }
    }
    
    //int closedList[20000][9];
    
    openList[0][0] = currentPos[0];
    openList[0][1] = currentPos[1];

    nextPositions();
    //openList[0][2] = 
    
    

    for (int i = 0; i < openListLen; i++)
    {
        free(openList[i]);
    }
    free(openList);
    
}

void nextPositions()
{
    char moves[4] = {'l', 'r', 'u', 'd'};
    
    for (int c = 0; c < 4; c++)
    {
        int arrayToPass[9];
        for (int i = 0; i < 9; i++)
        {
            arrayToPass[i] = currentPos[0][i];
        }
        
        if (moveBlank(arrayToPass, 3, moves[c]))
        {
            // should check if the position is already in the list and do stuff depending on if it's open or closed
            for (int i = 0; i < openListLen; i++)
            {
                 if (compareArrays(arraytoPass, openList[i][0], 9))
                 {
                     if (openList[i][1][2] == 1){
                         // if the cost of the currentPos is lower
                         if (openList[i][1][0] > currentPos[1][0])
                         {
                             // replace the array cost (Manhattan Distance stays the same)
                             openList[i][1][0] = currentPos[1][0];
                         }
                     }
                     else
                     {
                         // do something with the closed list
                         if (openList)
                     }
                 }
                
            }
            
            
            openListLen ++;
            openList = (int***) realloc(openList, openListLen * sizeof(int**));
            openList[openListLen - 1] = (int**) malloc(2 * sizeof(int*));
            for (int j = 0; j < 2; j ++)
            {
                openList[openListLen - 1][j] = (int*) malloc(9 * sizeof(int));
            }
             
            for (int i = 0; i < 9; i++)
            {
                openList[openListLen - 1][0][i] = arrayToPass[i];
                printf("%d ", openList[openListLen - 1][0][i]);
            }
            printf("\n");
            
            openList[openListLen - 1][1][0] = currentPos[1][0] + 1;
            openList[openListLen - 1][1][1] = manhattanDistance(openList[openListLen - 1][0], 3);
            openList[openListLen - 1][1][2] = 1;
            
        }
        
    }
    printf("openList: \n");
    for (int i = 0; i < openListLen; i++)
            {
                printf("{ {");
                for (int j = 0; j < 9; j++)
                {
                    printf("%d ", openList[i][0][j]);
                }
                printf("} {");
                for (int j = 0; j < 3; j++)
                {
                    printf("%d ", openList[i][1][j]);
                }
                printf("} }\n");
            }
}

bool moveBlank(int array[], int dim, char direction)
{
    int blankPos = findBlank(array, dim * dim);
    
    switch(direction)
    {
        case 'l':
            if (blankPos % dim != 0)
            {
                switchValues(array, blankPos, blankPos - 1);
                return true;
            }
            break;
        case 'r':
            if (blankPos % dim != dim - 1)
            {
                switchValues(array, blankPos, blankPos + 1);
                return true;
            }
            break;
        case 'u':
            if (blankPos > dim - 1)
            {
                switchValues(array, blankPos, blankPos - dim);
                return true;
            }
            break;
        case 'd':
            if (blankPos < dim * (dim - 1))
            {
                switchValues(array, blankPos, blankPos + dim);
                return true;
            }
            break;
    }
    return false;
    
}

int findBlank(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == 0)
        {
            return i;
        }
    }
    return - 1;
}

int manhattanDistance(int array[], int dim)
{
    int distance = 0;
    
    for (int i = 0; i < dim * dim; i++)
    {
        int targetPos = array[i] - 1;
        if (array[i] == 0)
        {
           targetPos = dim * dim - 1;
        }
        
        int targetRow = targetPos / dim;
        int targetCol = (targetPos) % dim;
        
        int iRow = i / dim;
        int iCol = i % dim;
        
        int curDistance = abs(targetRow - iRow) + abs(targetCol - iCol);
        distance += curDistance;
    }
    return distance;
}

void switchValues (int array[], int index1, int index2)
{
    int tempVal = array[index1];
    array[index1] = array[index2];
    array[index2] = tempVal;
}

void draw(int array[])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (array[i * 3 + j] < 10)
            {
                printf(" ");
            }
            if (array[i * 3 + j] == 0)
            {
                printf(" _");
            }
            else
            {
                printf(" %d", array[i * 3 + j]);
            }
        }
        printf("\n");
    }
}

void changeArraySize (int*** array, int len)
{
    array = (int***) realloc(array, len * sizeof(int**));
    
    //for (int i = 0; i < len; i++)
    //{
        array[len - 1] = (int**) malloc(2 * sizeof(int*));
        for (int j = 0; j < 2; j ++)
        {
            array[len - 1][j] = (int*) malloc(9 * sizeof(int));
        }
    //}
    
}

void freeArray (int*** array, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);
}

bool compareArrays(int a[]; int b[], int len)
{
    for (int i = 0; i < len; i ++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}