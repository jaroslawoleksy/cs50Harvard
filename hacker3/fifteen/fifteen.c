/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int zeroPos[2];

// functions
bool isArrayPermutationsEven(int array[], int n);
void switchValues (int array[], int index1, int index2);
bool isSolvable (int array[], int dimension, int zeroRow);
void godMode (int array[], int n);
int manhattanDistance(int array[], int dim);


int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(500000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    int array[d * d];
    
    for (int i = 0; i < d * d; i++)
    {
        array[i] = i;
        
    }
    
    for (int i = 0; i < d * d; i++)
    {
        int temp = array[i];
        int randomIndex = rand() % (d * d);
        
        array[i] = array[randomIndex];
        array[randomIndex] = temp;
        printf("%d,", array[i]);
    }
    
    if (!isSolvable(array, d, zeroPos[1])) // still to be made
    {
        int index1 = d * d - 2;
        int index2 = d * d - 1;
        if (array[index1] == 0)
        {
            index1--;
        }
        if (array[index2] == 0)
        {
            index2 -= 2;
        }
        switchValues(array, index1, index2);
    }
    
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            board[i][j] = array[i * d + j];
            if (board[i][j] == 0)
            {
                zeroPos[0] = i;
                zeroPos[1] = j;
            }
        }
    }
    
    
    
    
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] < 10)
            {
                printf(" ");
            }
            if (board[i][j] == 0)
            {
                zeroPos[0] = i;
                zeroPos[1] = j;
                printf(" _");
            }
            else
            {
                printf(" %d", board[i][j]);
            }
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == tile)
            {
                if (i + 1 == zeroPos[0] && j == zeroPos[1])
                {
                    board[i][j] = 0;
                    board[i + 1][j] = tile;
                    return true;
                }
                else if (i - 1 == zeroPos[0] && j == zeroPos[1])
                {
                    board[i][j] = 0;
                    board[i - 1][j] = tile;
                    return true;
                }
                else if (j + 1 == zeroPos[1] && i == zeroPos[0])
                {
                    board[i][j] = 0;
                    board[i][j + 1] = tile;
                    return true;
                }
                else if (j - 1 == zeroPos[1] && i == zeroPos[0])
                {
                    board[i][j] = 0;
                    board[i][j - 1] = tile;
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int result = 0;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            int controlSum = i*d + j + 1;
            if (controlSum == d * d)
            {
                controlSum = 0;
            }
            if (board[i][j] == controlSum)
            {
                result++;
            }
        }
    }
    if (result == d * d)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isArrayPermutationsEven(int array[], int n)
{
    int inversions = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[j] > array[i] && array[i] != 0 && array[j] != 0)
            {
                inversions++;
            }
        }
        
    }
    if (inversions % 2 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    
}


void switchValues (int array[], int index1, int index2)
{
    int tempVal = array[index1];
    array[index1] = array[index2];
    array[index2] = tempVal;
}

bool isSolvable (int array[], int dimension, int zeroRow)
{
    int length = dimension * dimension;
    if (dimension % 2 != 0)
    {
        return isArrayPermutationsEven(array, length);
    }
    else if ((dimension - zeroRow) % 2 == 0)
    {
        return !isArrayPermutationsEven(array, length);
    }
    else
    {
        return isArrayPermutationsEven(array, length);
    }
    
}

void godMode (int array[], int n)
{
    int goalState[n];
    for (int i = 0; i < n - 1, i++)
    {
        goalState[i] = i + 1;
    }
    goalState[n - 1] = 0;
    
    
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