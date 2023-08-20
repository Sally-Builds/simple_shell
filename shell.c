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

	while (true)
	{
		printf("#cisfun$ ");

		if (getline(&buffer, &buffer_size, stdin) != -1)
		{
			run_shell(buffer);
		}
		else
		{
			return (1);
		}
	}

	free(buffer);
	return (0);
}
