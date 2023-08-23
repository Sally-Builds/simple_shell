#include "main.h"
/**
 * main - simple shell
 * Return: 0 or 1
 */
int main(void)
{
	char *buffer;
	char **argv;

	while (true)
	{
		printf("#cisfun$ ");

		buffer = read_input();

		if (buffer == NULL)
			return (1);
		argv = split_command(buffer);

		if (argv[0] != NULL)
			run_sh(argv);

		free(buffer);
		free(argv);
	}
	return (0);
}
