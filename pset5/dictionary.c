/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "dictionary.h"
    
node* root = NULL;
int dictSize = 0;


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{

    node* currentNode = root;
    for (int i = 0; i < strlen(word); i++)
    {
        
        int index = (int)tolower(word[i]) - (int)'a';
        if (word[i] == '\'')
        {
            index = 26;
        }
        if (currentNode -> children[index] == NULL)
        {
            return false;
        }
        else
        {
            currentNode = currentNode -> children[index];
        }
    }
    if (currentNode -> is_word == true)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    
    root = initializeNode();
    
    node* currentNode = root;
    
    dictSize = 0;
    FILE* dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
    char word[LENGTH+1];
    
    for (char* result = fgets(word, LENGTH + 2, dict); result != NULL; result = fgets(word, LENGTH + 2, dict))
    {
        
        if (result != NULL)
        {
            
            for (int i = 0; i < strlen(word) -1; i++)
            {
                int index = (int)word[i] - (int)'a';
                if (word[i] == '\'')
                {
                    index = 26;
                }
                
                if (currentNode -> children[index] == NULL)
                {
                    
                    currentNode -> children[index] = initializeNode();
                    currentNode = currentNode -> children[index];
                }
                else
                {
                    currentNode = currentNode -> children[index];
                }
                
            }
            currentNode -> is_word = true;
            dictSize++;
            
        }
        currentNode = root;
        
        
    }
    
    fclose(dict);
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dictSize;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    emptyTrie(root);
    
    return true;
}

void emptyTrie(struct node *cursor)
{
    for (int i = 0; i < 27; i++)
    {
        if (cursor -> children[i] != NULL)
        {
            emptyTrie(cursor -> children[i]);
        }
        
    }
    free(cursor);
}

struct node *initializeNode(void)
{
    struct node *pNode = NULL;
    
    pNode = (struct node *)malloc(sizeof(struct node));
    if(pNode)
    {
        pNode -> is_word = false;
        
        for (int i = 0; i < 27; i++)
        {
            pNode -> children[i] = NULL;
        }
        
    }
    
    return pNode;
}