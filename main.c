#include "main.h"


int main(int argc __attribute__((unused)), char **argv)
{
    char **current_command = NULL;
    int i, type_command = 0;
    size_t n = 0;

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
        g_commands = tokenizer(g_line, ";");

        for (i = 0; g_commands[i] != NULL; i++)
        {
            current_command = tokenizer(g_commands[i], " ");
            if (current_command[0] == NULL)
            {
                free(current_command);
                break;
            }
            type_command = parse_command(current_command[0]);

            /* initializer -   */
            initializer(current_command, type_command);
            free(current_command);
        }
        free(g_commands);
    }
    free(g_line);

    return (g_status);
}
