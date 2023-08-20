#include "main.h"
/**
*executor- takes command and executes it
*@tokens: null terminated array of strings
*desription: gets a command from gettoken and executes it
*Return: result output based on command mimicking Linux bash
*/
int executor(char *tokens[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("./hsh");
		return (-1);
	}
	else if (child_pid == 0)
	{
		if (execve(tokens[0], tokens, environ) == -1)
		{
			write(2, tokens[0], strlen(tokens[0]));
			write(2, ": command not found\n", sizeof(": command not found\n") - 1);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
