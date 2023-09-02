#include "main.h"

/**
 * handle_built_in_commands - handle builtin exit and env
 * @args: arguments
 */
void handle_built_in_commands(char *args[])
{
	if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		char **env = environ;

		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
	}
}
