#include "main.h"

/**
 * execute_command - execute shell command
 * @args: command line arguments
 */
void execute_command(char *args[])
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execvp(args[0], args);
		perror(args[0]);
		_exit(EXIT_FAILURE);
	}
	else
	{

		int status;

		waitpid(pid, &status, 0);
	}
}
