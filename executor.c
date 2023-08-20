#include "main.h"
/**
*executor- takes command and executes it
*@tokens: null terminated array of strings
*desription: gets a command from gettoken and executes it
*Return: result output based on command mimicking Linux shell or,
*        error if command cannot be found and prompt again
*/
int executor(char *tokens[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("error forking:");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(tokens[0], tokens, environ) == -1)
		{
			printf("%s: command not found\n", tokens[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
