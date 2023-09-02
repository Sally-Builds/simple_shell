#include "main.h"

/**
 * main - entry point
 * Return: 0 or 1
 */
int main(void)
{
	signal(SIGINT, handle_signal);

	while (1)
	{
		process_input();
	}

	return (0);
}
