#include "main.h"
/**
 * read_input - read user input
 *
 * Return: user input
 */
char *read_input()
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	size_t buffer_length;

	buffer_length = getline(&buffer, &buffer_size, stdin);

	if (buffer_length == -1)
	{
		return (NULL);
	}
	return (buffer);
}
