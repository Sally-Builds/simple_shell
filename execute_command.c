#include "main.h"
/**
 * execute_command - function to execute the users inputted command
 * @argv: users inputted command
 */
void execute_command(char **argv)
{
	if (*argv[0] == '\0')
		exit(1);

	if (argv)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(argv[0]);
			exit(1);
		}
	}
}
