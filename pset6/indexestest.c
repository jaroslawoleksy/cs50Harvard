#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* indexes(const char* path);

int main(void)
{
    const char* path = "public/test/";
    printf("%d %c\n", (int)strlen(path), path[strlen(path) - 1]);
    
    printf("%s\n", indexes(path));

}

char* indexes(const char* path)
{
    char* fullPath = malloc(strlen(path) + sizeof("index.php") + 1);
    strcat(fullPath, path);
    /*
    if(path[strlen(path) - 1] != '/')
    {
        strcat(fullPath, "/");
    }
    */
    strcat(fullPath, "index.php");
    if (access(fullPath, R_OK) == 0)
    {
        return fullPath;
    }
    
    /*
    FILE* inptr = fopen(fullPath, "r");
        if (inptr != NULL)
        {
            fclose(inptr);
            return fullPath;
        }
    */
    free(fullPath);
    fullPath = malloc(strlen(path) + sizeof("index.html") + 2);
    strcat(fullPath, path);
    if(path[strlen(path) - 1] != '/')
    {
        strcat(fullPath, "/");
    }
    strcat(fullPath, "index.html");
    if (access(fullPath, R_OK) == 0)
    {
        return fullPath;
    }
    /*
    inptr = fopen(fullPath, "r");
        if (inptr != NULL)
        {
            fclose(inptr);
            return fullPath;
        }
    */
    free(fullPath);
    return NULL;
}