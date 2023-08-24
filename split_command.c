#include "main.h"

char **split_command(char *buffer);
char **split_tokens(char *buffer_duplicate, const char *delim);
void allocate_memory_for_argv(char ***argv, int size);
void free_argv(char **argv);
/**
 * split_command - split buffer into argv
 * @buffer: input buffer to split
 *
 * Return: array of string argv
 */
char **split_command(char *buffer)
{
	const char *delim = " \n";
	char *buffer_duplicate;
	char **argv;

	buffer_duplicate = strdup(buffer);
	if (buffer_duplicate == NULL)
	{
		perror("Memory allocation error");
		exit(1);
	}

	argv = split_tokens(buffer_duplicate, delim);

	free(buffer_duplicate);
	return (argv);
}

/**
 * split_tokens - splts token
 * @buffer_duplicate: buffer to split
 * @delim: delimeter
 *
 * Return: split array
 */
char **split_tokens(char *buffer_duplicate, const char *delim)
{
	char *token;
	int i = 0;
	char **argv = NULL;

	token = strtok(buffer_duplicate, delim);

	while (token != NULL)
	{
		allocate_memory_for_argv(&argv, i + 1);
		argv[i] = strdup(token);
		if (argv[i] == NULL)
		{
			perror("Memory allocation error");
			exit(1);
		}
		i++;

		token = strtok(NULL, delim);
	}

	allocate_memory_for_argv(&argv, i + 1);
	argv[i] = NULL;

	return (argv);
}

/**
 * allocate_memory_for_argv - memory allocation for argv
 * @argv: argv
 * @size: size of argv
 */
void allocate_memory_for_argv(char ***argv, int size)
{
	*argv = realloc(*argv, size * sizeof(char *));
	if (*argv == NULL)
	{
		perror("Memory allocation error");
		exit(1);
	}
}
