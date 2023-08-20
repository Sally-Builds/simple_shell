#include "main.h"
/**
 * run_shell - function that calls the child process
 *
 * @buffer: command to execute
 *
 * Return: void
 */
void run_shell(char **argv)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
	}
	if (child_pid == 0)
	{
		if (*argv[0] == '\0')
			argv[0] = " ";
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
		}
	}
	else
	{
		wait(NULL);
	}
}
