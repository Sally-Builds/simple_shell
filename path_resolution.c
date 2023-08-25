#include "main.h"

/**
 * check_path - checks path of command
 * @command: command to check
 *
 * Return: absolute path
 */
char *check_path(char *command)
{
	char **path_array = NULL;
	char *temp, *temp2, *path_cpy;
	char *path = _getenv("PATH");
	int i = 0;

	if (path == NULL || _strlen(path) == 0)
		return (NULL);

	path_cpy = malloc(sizeof(*path_cpy) * (_strlen(path) + 1));
	_strcpy(path, path_cpy);
	path_array = get_token(path_cpy, ":");

	while (path_array[i] != NULL)
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
		i++;  /** Increment i in each iteration*/
	}

	free(path_cpy);
	free(path_array);
	return (NULL);
}

/**
 * _getenv - get value of specific env variable
 * @name: - name of env variable
 * Return: value of env variable
 */
char *_getenv(char *name)
{

	char *p_ptr;
	char **dup_environ;
	char *name_cpy;

	dup_environ = environ;
	while (*dup_environ != NULL)
	{
		p_ptr = *dup_environ;
		name_cpy = name;

		while (*p_ptr == *name_cpy)
		{
			if (*p_ptr == '=')
				break;

			p_ptr++;
			name_cpy++;
		}

		if ((*p_ptr == '=') && (*name_cpy == '\0'))
			return (p_ptr + 1);

		dup_environ++;
	}

	return (NULL);
}
