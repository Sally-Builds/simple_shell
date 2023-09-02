#include "main.h"

/**
 *  handle_signal - handles the process signals
 *  @signum: signal number
 */
void handle_signal(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
	}
}
