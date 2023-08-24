#include "main.h"

char *check_path(char *command)

{

    char **path_array = NULL;

    char *temp, *temp2, *path_cpy;

    char *path = _getenv("PATH");

    int i;



    if (path == NULL || _strlen(path) == 0)

        return (NULL);

    path_cpy = malloc(sizeof(*path_cpy) * (_strlen(path) + 1));

    _strcpy(path, path_cpy);

    path_array = tokenizer(path_cpy, ":");

    for (i = 0; path_array[i] != NULL; i++)

    {

        temp2 = _strcat(path_array[i], "/");

        temp = _strcat(temp2, command);

        if (access(temp, F_OK) == 0)

        {

            free(temp2);

            free(path_array);

            free(path_cpy);

            return (temp);

        }

        free(temp);

        free(temp2);

    }

    free(path_cpy);

    free(path_array);

    return (NULL);

}


char *_getenv(char *name)
{
    char **my_environ;
    char *pair_ptr;
    char *name_cpy;

    for (my_environ = environ; *my_environ != NULL; my_environ++)
    {
        for (pair_ptr = *my_environ, name_cpy = name;
             *pair_ptr == *name_cpy; pair_ptr++, name_cpy++)
        {
            if (*pair_ptr == '=')
                break;
        }
        if ((*pair_ptr == '=') && (*name_cpy == '\0'))
            return (pair_ptr + 1);
    }
    return (NULL);
}
