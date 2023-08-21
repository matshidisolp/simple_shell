#include "main.h"

/**
  *handle_exit- terminates the program using kill
  *@tokens: null terminated array of strings
  *description: mimicks Linux bash when user inputs exit
  *		program terminates
  */
void handle_exit(char *tokens[])
{
	int i = 0;
	size_t token_len = _strlen_recursion(tokens[i]);
	char *token_cpy = _strdup(tokens[i]);

	if (token_cpy == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}
	if (token_cpy[token_len - 1] == '\n')
		token_cpy[token_len - 1] = '\0';
	if (_strcmp(token_cpy, "exit") == 0)
	{
		free(token_cpy);
		exit(0);
		/*kill(getpid(), SIGTERM);*/
	}
}
