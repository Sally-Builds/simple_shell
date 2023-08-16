#include "main.h"

/**
 * main - entry point
 *
 * Return: void
 */
int main(void)
{
	char *buffer;
	size_t buffer_size = 32;

	buffer = (char *)malloc(buffer_size * sizeof(char));

	if (buffer == NULL)
	{
		perror("Error");
		return (1);
	}
	printf("$ ");
	while (getline(&buffer, &buffer_size, stdin))
	{
		run_shell(buffer);
	}

	free(buffer);
}
