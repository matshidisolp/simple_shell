#include "main.h"
/**
  *main- driver function
  *Return: 0
  */
int main(void)
{
	int status;
	size_t n;
	char *buff, *delim;
	char **tokens;

	delim = " \n\t\a\r";
	status = 0;
	do {
		prompt();
		status = readline(&buff, &n);
		tokens = get_token(buff, delim);
		if (*buff == '\n' || *tokens == NULL)
		{
			free(tokens);
			continue;
		}
		handle_exit(tokens);
		lunch(tokens);
		free(tokens);
	} while (status != -1);
	free(buff);
	return (0);
}
