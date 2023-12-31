#include "main.h"

int g_status = 0;
char *g_line = NULL;

char *g_shell_name = NULL;
char **g_commands = NULL;

/**
 * main - entry point
 * @argc:  number of argv
 * @argv: variable number of argument
 *
 * Return: 0 or 1
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char **current_command = NULL;
	size_t n = 0;
	int i = 0;
	int type_command = 0;

	signal(SIGINT, ctrl_c_handler);
	g_shell_name = argv[0];
	while (1)
	{
		non_interactive();
		print("#cisfun$ ", STDOUT_FILENO);
		if (getline(&g_line, &n, stdin) == -1)
		{
			free(g_line);
			exit(g_status);
		}
		remove_newline(g_line);
		remove_comment(g_line);
		g_commands = get_token(g_line, ";");

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
		i = 0;
	}
	free(g_line);

	return (g_status);
}

/**
 * get_token - get token from input
 * @input_string: input string
 * @delim: delimeter
 *
 * Return: Pointer to array of strings
 */
char **get_token(char *input_string, char *delim)
{
	int num_delim = 0;
	char **av = NULL;
	char *token = NULL;
	char *save_ptr = NULL;

	token = _strtok_r(input_string, delim, &save_ptr);

	for (; token != NULL; num_delim++)
	{
		av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
		av[num_delim] = token;
		token = _strtok_r(NULL, delim, &save_ptr);

	}

	av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));

	av[num_delim] = NULL;

	return (av);

}

/**
 * remove_comment - get rid of comment in input
 * @input: string
 */
void remove_comment(char *input)
{
	int i = 0;

	if (input[i] == '#')
		input[i] = '\0';
	while (input[i] != '\0')
	{
		if (input[i] == '#' && input[i - 1] == ' ')
			break;
		i++;
	}
	input[i] = '\0';
}
