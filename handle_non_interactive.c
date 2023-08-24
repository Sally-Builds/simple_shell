#include "main.h"

void non_interactive(void)

{

    char **current_command = NULL;

    int i, type_command = 0;

    size_t n = 0;



    if (!(isatty(STDIN_FILENO)))

    {

        while (getline(&g_line, &n, stdin) != -1)

        {

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

                initializer(current_command, type_command);

                free(current_command);

            }

            free(g_commands);

        }

        free(g_line);

        exit(g_status);

    }

}
