#include "main.h"

void run_shell(char *buffer)
{
		size_t child_pid = fork();
                  char *argv[] = {strtok(buffer, "\n"), NULL};
                  
                  if(child_pid == -1)
                  {
                          perror("Error");
                  }       
                  
                 if (child_pid == 0)
                 {
                         if (argv[0] == '\0')
                                 argv[0] = " ";
                         if (execve(argv[0], argv, NULL) == -1 )
                         {
                                 perror("Error");
                                 printf("$ ");
                         }       
                  } else {
                          wait(NULL);
                          printf("$ ");
                  }
}
