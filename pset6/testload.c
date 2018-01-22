#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char BYTE;

bool load(FILE* file, BYTE** content, size_t* length);

int main(void)
{
    FILE* file;
    file = fopen("public/cat.html", "r");
    char* content;
    size_t length;
    load(file, &content, &length);
    
    fclose(file);
}

bool load(FILE* file, BYTE** content, size_t* length)
{
    // TODO
    BYTE* buffer = (BYTE*)malloc(sizeof(BYTE));
    
    *length = 1;
    
    for (char c = fgetc(file); c != EOF; c = fgetc(file))
    {
        buffer[*length - 1] = c;
        *length = *length + 1;
        buffer = (BYTE*)realloc(buffer, *length * (sizeof(BYTE)));
    }
    *content = &buffer;
    return true;
}