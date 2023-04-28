#include"shell.h"
/**
 * _strtok - separates strings with delimiters
 * @string: string input
 * Return: the created token's pointer
 */
char **_strtok(char *args)
{
        int bufsize, i = 0;
        char **tokens;
        char *token;

        bufsize = RL_BUFFER_SIZE;
        tokens = malloc(bufsize * sizeof(char*));
        if (!tokens)
        {
                fprintf(stderr, "error\n");
                exit(EXIT_FAILURE);
        }
        token = strtok(args, DELIM);
        while (token != NULL)
        {
                tokens[i] = token;
                token = strtok(NULL, "\n\t\r");
                i++;
        }
  tokens[i] = NULL;
  return (tokens);
}

