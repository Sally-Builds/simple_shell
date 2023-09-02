#include "main.h"

/**
 * tokenize_command - tokenization
 * @command: user inputed command
 * @args: arguments
 * @num_args: number of arguments
 */
void tokenize_command(char *command, char *args[], int *num_args)
{
	char *token;

	token = strtok(command, " ");

	while (token != NULL)
	{
		args[(*num_args)++] = token;
		token = strtok(NULL, " ");
	}
	args[*num_args] = NULL;
}
