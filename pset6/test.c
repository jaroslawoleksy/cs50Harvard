#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool parse(const char* line, char* abs_path, char* query);

int main(void)
{
    char *line = "abcGET /cat.php? HTTP/1.1\r\n";
    char abs_path[30];
    char query[30];
    
    if (parse(line, abs_path, query))
    {
        printf("Succeed\n");
    }
    
}

bool parse(const char* line, char* abs_path, char* query)
{
    int i = 3;
    char method[4];
    strncpy(method, line, 3);
    method[3] = '\0';
    
    if (line[i] != ' ')
    {
        printf("error(400)");
        return false;
    }
    
    bool isQuery = false;
    int j = 0, k = 0;
    for (i = 4; i < strlen(line); i++)
    {
        if (line[i] == ' ')
        {
            if (isQuery)
            {
                query[k] = '\0';
            }
            break;
        }
        if (line[i] == '?')
        {
            if (line[i + 1] == ' ')
            {
                i++;
                break;
            }
            isQuery = true;
            i++;
        }
        if (isQuery == false)
        {
            abs_path[j] = line[i];
            j++;
        }
        else
        {
            query[k] = line[i];
            k++;
        }
    }
    if (!isQuery)
    {
        query = "";
    }
    j = 0;
    char httpVersion[12];
    for (i = i + 1; i < strlen(line); i++)
    {
        httpVersion[j] = line[i];
        j++;
    }
    httpVersion[j] = '\0';
    
    printf("method:%s path:%s query:%s http:%s\n", method, abs_path, query, httpVersion);
    printf("strlen: %d i: %d\n", (int)strlen(line), i);
    
    if (strcmp(method, "GET") != 0)
    {
        printf("Error 405");
        return false;
    }
    if (abs_path[0] != '/')
    {
        printf("Error 501");
        return false;
    }
    
    if (strchr(query, '"') != NULL)
    {
        printf("Error 400");
        return false;
    }
    
    if (strcmp(httpVersion, "HTTP/1.1\r\n") != 0)
    {
        printf("Error 505");
        return false;
    }
    
    return true;
}