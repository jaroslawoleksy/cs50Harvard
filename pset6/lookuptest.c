#include <stdio.h>
#include <string.h>
#include <strings.h>


const char* lookup(const char* path);

int main(void)
{
    const char* path = "public/cat.jpg";
    printf("path: %s\n", lookup(path));
}

const char* lookup(const char* path)
{
    // TODO
    char *extension;
    extension = strrchr(path, '.');
    if (strcasecmp(extension, ".css") == 0)
    {
        return "text/css";
    }
    else if (strcasecmp(extension, ".html") == 0)
    {
        return "text/html";
    }
    else if (strcasecmp(extension, ".gif") == 0)
    {
        return "image/gif";
    }
    else if (strcasecmp(extension, ".ico") == 0)
    {
        return "image/x-icon";
    }
    else if (strcasecmp(extension, ".jpg") == 0)
    {
        return "image/jpeg";
    }
    else if (strcasecmp(extension, ".js") == 0)
    {
        return "text/javascript";
    }
    else if (strcasecmp(extension, ".php") == 0)
    {
        return "text/x-php";
    }
    else if (strcasecmp(extension, ".png") == 0)
    {
        return "image/png";
    }
    else
    {
        return NULL;
    }
}