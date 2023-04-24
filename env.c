#include "shell.h"


int _env(void)
        {
                unsigned int i;


                for (i = 0; environ[i]; i++)
                {
                        write(STDOUT_FILENO, environ[i],strlen(environ[i]));
                        write(STDOUT_FILENO, "\n", 1);
                }
                return (0);
        }
