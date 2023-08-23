#include "main.h"

/**
 * store_token_in_array - split string according to delimeter
 * @argv: array of strings to store the spli strings
 * @s: string to split
 * @delim: delimeter
 */
void store_token_in_array(char **argv, char *s, char *delim)
{
	int i = 0;
	char *token = strtok(s, delim);

	while (token != NULL)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		token = strtok(NULL, " \t\r\n");
		i++;
	}
	argv[i] = NULL;
}
