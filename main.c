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

char **tokenizer(char *input_string, char *delim)

{

    int num_delim = 0;

    char **av = NULL;

    char *token = NULL;

    char *save_ptr = NULL;



    token = _strtok_r(input_string, delim, &save_ptr);



for (; token != NULL; num_delim++)

    {

        av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));

        av[num_delim] = token;

        token = _strtok_r(NULL, delim, &save_ptr);

    }



    av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));

    av[num_delim] = NULL;



    return (av);

}



void print(char *string, int stream)

{

    int i = 0;



    for (; string[i] != '\0'; i++)

        write(stream, &string[i], 1);

}
