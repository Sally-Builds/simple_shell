#include "main.h"

/**
 * print - print string to a specific stream
 * @string: string to print
 * @stream: stream to print string to
 */
void print(char *string, int stream)
{
	int i = 0;

	for (; string[i] != '\0'; i++)
		write(stream, &string[i], 1);
}

/**
 * remove_newline - removes the newline char from string
 * @str: string
 */
void remove_newline(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	str[i] = '\0';
}
