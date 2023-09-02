#include "main.h"

/**
 * ctrl_c_handler - handle signal
 * @signum: signal
 */
void ctrl_c_handler(int signum)
{
	if (signum == SIGINT)
		print("\n#cisfun$ ", STDIN_FILENO);
}
