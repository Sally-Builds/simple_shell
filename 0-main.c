#include "main.h"
/**
 * main - simple shell
 * @argc: number of argument
 * @argvs: variable number of argument
 * Return: 0 or 1
 */
int main()
{
	while (true)
	{
		printf("#cisfun$ ");

		char *buffer = read_input();
		if(buffer == NULL)
			return (1);
		char **argv = split_command(buffer);

		if (argv[0] != NULL)
			run_sh(argv);

		free(buffer);
		free(argv);
	}
	return (0);
}
