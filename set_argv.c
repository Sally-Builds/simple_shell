#include "main.h"


int set_argv(char *buffer, char **argv)
{

	int i = 0;

	char *token = strtok(buffer, " \t\r\n");

	while(token != NULL)
	{
		argv[i] = token;
		token = strtok(NULL, " \t\r\n");
		i++;
	}
	argv[i] = NULL;
	return (i);
}
