#include "main.h"
/**
 * run_shell - function that calls the child process
 *
 * @buffer: command to execute
 *
 * Return: void
 */
void run_shell(char *buffer)
{
	pid_t child_pid = fork();
	char *ch = strtok(buffer, "\n");
	char *argv[2];
	argv[0] = ch;
	argv[1] = NULL;
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
			printf("from err - $ ");
		}
	}
	else
	{
		wait(NULL);
		/**printf("from parent - $ ");*/
	}
}
