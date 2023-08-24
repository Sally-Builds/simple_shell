#include "main.h"

void print(char *string, int stream)
{
    int i = 0;

    for (; string[i] != '\0'; i++)
        write(stream, &string[i], 1);
}

void remove_newline(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            break;
        i++;
    }
    str[i] = '\0';
}
