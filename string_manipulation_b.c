#include "main.h"


int _strcspn(char *str1, char *str2)
{
    int len = 0, i;

    for (i = 0; str1[i] != '\0'; i++)
    {
        if (_strchr(str2, str1[i]) != NULL)
            break;
        len++;
    }
    return (len);
}

char *_strchr(char *s, char c)
{
    int i = 0;

    for (; s[i] != c && s[i] != '\0'; i++)
        ;
    if (s[i] == c)
        return (s + i);
    else
        return (NULL);
}

char *_strtok_r(char *string, char *delim, char **save_ptr)
{
    char *finish;

    if (string == NULL)
        string = *save_ptr;

    if (*string == '\0')
    {
        *save_ptr = string;
        return (NULL);
    }

    string += _strspn(string, delim);
    if (*string == '\0')
    {
        *save_ptr = string;
        return (NULL);
    }

    finish = string + _strcspn(string, delim);
    if (*finish == '\0')
    {
        *save_ptr = finish;
        return (string);
    }

    *finish = '\0';
    *save_ptr = finish + 1;
    return (string);
}

int _atoi(char *s)
{
    unsigned int n = 0;

    do {
        if (*s == '-')
            return (-1);
        else if ((*s < '0' || *s > '9') && *s != '\0')
            return (-1);
        else if (*s >= '0' && *s <= '9')
            n = (n * 10) + (*s - '0');
        else if (n > 0)
            break;
    } while (*s++);
    return (n);
}
