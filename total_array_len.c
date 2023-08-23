#include "main.h"

/**
 * get_len_of_argv - get length of string split by delim
 * @buff_dup: string to split
 * @delim: delimeter
 *
 * Return: length of string split by delim
 */
int get_len_of_argv(char *buff_dup, char *delim)
{
	int i = 0;
	char *token;

	token = strtok(buff_dup, delim);

	while (token != NULL)
	{
		i++;
		token = strtok(NULL, delim);
	}
	return (i);
}
