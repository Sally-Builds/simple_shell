#include "main.h"

/**
 * main - entry point
 *
 * Return: void
 */
int main(void)
{
	char *buffer;
	char **argv;
	size_t buffer_size = 32;

	buffer = (char *)malloc(buffer_size * sizeof(char));
	argv = (char **)malloc(buffer_size * sizeof(char));

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
			set_argv(buffer, argv);
			run_shell(argv);
		}
		else
		{
			return (1);
		}
	}

	free(buffer);
	free(argv);
	return (0);
}
