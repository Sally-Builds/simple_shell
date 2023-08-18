#include "main.h"

/**
 * main - entry point
 *
 * Return: void
 */
int main(void)
{
	char *buffer;
	size_t buffer_size = 32;

	buffer = (char *)malloc(buffer_size * sizeof(char));

	if (buffer == NULL)
	{
		perror("Error");
		return (1);
	}

	do {
		printf("from before shell - $ ");
		run_shell(buffer);
	}
	while (getline(&buffer, &buffer_size, stdin) != EOF);

	free(buffer);
	return (0);
}
