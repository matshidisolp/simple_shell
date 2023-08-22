#include "main.h"

/**
  *handle_exit- terminates the program using kill
  *@tokens: null terminated array of strings
  *description: mimicks Linux bash when user inputs exit
  *		program terminates
  */
void handle_exit(char *tokens[], char *buff)
{

	if (_strcmp(tokens[0], "exit") == 0)
	{
		free(tokens);
		free(buff);
		exit(EXIT_SUCCESS);
	}
}
