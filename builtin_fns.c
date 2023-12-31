#include "main.h"

/**
 * env - handle env built-in cmd
 * @tokenized_command: - command
 */
void env(char **tokenized_command __attribute__((unused)))
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{

		print(environ[i], STDOUT_FILENO);

		print("\n", STDOUT_FILENO);

	}

}

/**
 * quit - handle exit built-in command
 * @tokenized_command: - command
 */
void quit(char **tokenized_command)
{
	int num_token = 0, arg;

	for (; tokenized_command[num_token] != NULL; num_token++)
		;
	if (num_token == 1)
	{
		free(tokenized_command);
		free(g_line);
		free(g_commands);
		exit(g_status);
	}
	else if (num_token == 2)
	{
		arg = _atoi(tokenized_command[1]);
		if (arg == -1)
		{
			print(g_shell_name, STDERR_FILENO);
			print(": 1: exit: Illegal number: ", STDERR_FILENO);
			print(tokenized_command[1], STDERR_FILENO);
			print("\n", STDERR_FILENO);
			g_status = 2;
		}
		else
		{
			free(g_line);
			free(tokenized_command);
			free(g_commands);
			exit(arg);
		}
	}
	else
		print("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}
