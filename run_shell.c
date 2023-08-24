#include "main.h"

/**
 * initializer - initialize child process
 * @current_command: - command to run
 * @type_command: type of command to run
 */
void initializer(char **current_command, int type_command)
{
	pid_t PID;

	if (type_command == EXTERNAL_COMMAND || type_command == PATH_COMMAND)
	{
		PID = fork();

		if (PID == 0)

			execute_command(current_command, type_command);

		else

		{

			waitpid(PID, &g_status, 0);

			g_status >>= 8;

		}

	}

	else

		execute_command(current_command, type_command);

}
