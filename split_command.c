#include "main.h"
/**
 * split_command - split buffer into argv
 * @buffer: input buffer to split
 *
 * Return: array of string argv
 */
char **split_command(char *buffer)
{
	char *token;
	char *delim = " \n";
	int i = 0;
	char **argv;
	char *buffer_duplicate;
	int len_of_argv = 0;

	buffer_duplicate = malloc(sizeof(char *) * strlen(buffer));
	buffer_duplicate = strdup(buffer);

	len_of_argv = get_len_of_argv(buffer_duplicate, delim);
	printf("%s \n", buffer_duplicate);
	printf("%s \n", buffer);
	argv = malloc(sizeof(char *) * len_of_argv);

	token = strtok(buffer, delim);

	while (token != NULL)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		argv[i] = token;
		i++;

		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	return (argv);
}
