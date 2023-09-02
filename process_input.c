#include "main.h"

/**
 * process_input - handle user input
 */
void process_input(void)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t read_len;
	char *args[MAX_COMMAND_LENGTH];
	int num_args = 0;


	printf("#cisfun$ ");
	fflush(stdout);


	read_len = getline(&command, &len, stdin);
	if (read_len == -1)
	{

		printf("\n");
		free(command);
		exit(0);
	}


	if (command[read_len - 1] == '\n')
	{
		command[read_len - 1] = '\0';
	}


	tokenize_command(command, args, &num_args);


	handle_built_in_commands(args);


	execute_command(args);

	free(command);
}
