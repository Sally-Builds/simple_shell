#include "main.h"

void ctrl_c_handler(int signum)
{
    if (signum == SIGINT)
        print("\n($) ", STDIN_FILENO);
}
