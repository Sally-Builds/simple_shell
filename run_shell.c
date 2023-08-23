#include "main.h"
/**
 * run_shell - function to create a child process and execute command
 * @argv: users inputted command
 */
void run_shell(char **argv)
{
	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		execute_command(argv);
	}
	else
	{
		wait(NULL);
	}
}
