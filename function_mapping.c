#include "main.h"

/**
 * get_func -  get function for built-in command
 * @command: cmd
 *
 * Return: pointer to the function of the command found or NULL
 */
void (*get_func(char *command))(char **)
{
	int i;

	function_map mapping[] = {

		{"env", env}, {"exit", quit}

	};



	for (i = 0; i < 2; i++)

	{

		if (_strcmp(command, mapping[i].command_name) == 0)

			return (mapping[i].func);

	}

	return (NULL);

}
