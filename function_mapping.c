#include "main.h"

/**
 * run_function -  get function for built-in command
 * @command: cmd
 *
 * Return: pointer to the function of the command found or NULL
 */
void (*run_function(char *command))(char **)
{
	int i = 0;
	function_map mapping[] = {
		{"env", env}, {"exit", quit}
	};

	while (i < 2)
	{
		if (_strcmp(command, mapping[i].command_name) == 0)
			return (mapping[i].func);

		i++;
	}

	return (NULL);
}
