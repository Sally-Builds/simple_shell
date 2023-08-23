#include "main.h"

/**
 * total_len_of_string - get length of string split by delim
 * @s: string to split
 * @delim: delimeter
 *
 * Return: length of string split by delim
 */
int total_len_of_string(char *s, char *delim)
{
	int i = 0;
	char *token;

	token = strtok(s, delim);

	while (token != NULL)
	{
		i++;
		token = strtok(NULL, delim);
	}
	i++;

	return (i);
}
