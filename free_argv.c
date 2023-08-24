#include "main.h"

/**
 *free_argv - frees allocated memory space
 *@argv: the function parameter
 *Return: void
 */

void free_argv(char **argv)
{
	for (int i = 0; argv[i] != NULL; i++)
	{
		free(argv[i]);
	}
	free(argv);
}
