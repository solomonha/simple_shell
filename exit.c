#include "shell.h"
/* exit - exits the shell
 * @args: string
 * Return : an integer, zero if sucess
 */
int _exit(data d)
{
        int i;

        if (d->token[1] != NULL)

                {
                        for (i = 0; d->token[1][i]; i++)

                                if((data->token[1][i] < '0' || d->token[1][i] > '9')
                                        && d->token[1][i] != '+')

                                errno = 2
                                        return (2);
                }
        errno = atoi(data->tokens[1];
                        }
                        free(d);
                        exit(errno);
}
