#include "main.h"
/**
 * run_sh - function to create a child process and execute command
 * @argv: users inputted command
 */
void run_sh(char **argv)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
		exit(0);

	if (child_pid == 0)
	{
		exec_cmd(argv);
	}
	else
	{
		wait(NULL);
	}
}
