#include "main.h"
/**
 * execute_command - function to execute the users inputted command
 * @argv: users inputted command
 */
void exec_cmd(char **argv)
{
	if (*argv[0] == '\0')
		exit(1);

	if (argv)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("./shell");
			exit(1);
		}
	}
}
