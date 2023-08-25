#include "main.h"

/**
 * non_interactive - handle non interactive command
 */
void non_interactive(void)
{
	char **current_command = NULL;
	int i, type_command = 0;
	size_t n = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		for (;;)
		{
			if (getline(&g_line, &n, stdin) == -1)
				break;
			remove_newline(g_line);
			remove_comment(g_line);
			g_commands = get_token(g_line, ";");
			i = 0;

			while (g_commands[i] != NULL)
			{
				current_command = get_token(g_commands[i], " ");
				if (current_command[0] == NULL)
				{
					free(current_command);
					break;
				}
				type_command = parse_command(current_command[0]);
				create_child(current_command, type_command);
				free(current_command);
				i++;
			}
			free(g_commands);
		}
		free(g_line);
		exit(g_status);
	}
}
