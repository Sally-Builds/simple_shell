#include "main.h"

/**
 * parse_command - checks the type of command based on the command string.
 * @command:  users command
 *
 * Return: command status
 */
int parse_command(char *command)
{
	int i;
	char *internal_command[] = {"env", "exit", NULL};
	char *path = NULL;

	for (i = 0; command[i] != '\0'; i++)
	{
		if (command[i] == '/')
			return (EXTERNAL_COMMAND);
	}
	for (i = 0; internal_command[i] != NULL; i++)
	{
		if (_strcmp(command, internal_command[i]) == 0)
			return (INTERNAL_COMMAND);
	}
	path = check_path(command);
	if (path != NULL)
	{
		free(path);
		return (PATH_COMMAND);
	}
	return (INVALID_COMMAND);
}

/**
 * execute_command - execute the specific command based on its type
 * @tokenized_command: command which was tokenized
 * @command_type: type of command
 *
 * Return: void
 */
void execute_command(char **tokenized_command, int command_type)
{
	void (*func)(char **command);

	if (command_type == EXTERNAL_COMMAND)
	{
		if (execve(tokenized_command[0], tokenized_command, NULL) == -1)
		{
			perror(tokenized_command[0]);
			exit(2);
		}
	}
	if (command_type == PATH_COMMAND)
	{
		if (execve(check_path(tokenized_command[0]), tokenized_command, NULL) == -1)
		{
			perror(tokenized_command[0]);
			exit(2);
		}
	}
	if (command_type == INTERNAL_COMMAND)
	{
		func = run_function(tokenized_command[0]);
		func(tokenized_command);
	}
	if (command_type == INVALID_COMMAND)
	{
		print(tokenized_command[0], STDERR_FILENO);
		print(": no such file or directory\n", STDERR_FILENO);
		g_status = 127;
	}
}
