#include "main.h"
/**
 * main - simple shell
 * Return: 0 or 1
 */
int main(void)
{
	char *buffer = NULL;
	char *buffer_copy;
	size_t buffer_size = 32;
	int buffer_len;
	char *delim = " \t\r\n";
	char **argv;
	int len_of_argv;

	while (true)
	{
		printf("#cisfun$ ");
		buffer_len = getline(&buffer, &buffer_size, stdin);

		buffer_copy = malloc(sizeof(char) * buffer_len);

		if (buffer_len == -1)
		{
			return (1);
		}

		strcpy(buffer_copy, buffer);

		/*get the number of strings(commands, and arguments)*/
		len_of_argv = total_len_of_string(buffer_copy, delim);

		argv = (char **) malloc(len_of_argv * sizeof(char));

		/**store the commands in the argv array*/
		store_token_in_array(argv, buffer, delim);

		/*execute command*/
		run_shell(argv);
		free(buffer_copy);
	}
	return (0);
}
