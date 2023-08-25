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
	buff = NULL;
	n = 0;
	status = 0;
	if (isatty(STDIN_FILENO) == 1)
		prompt();

	while ((status = readline(&buff, &n)) != -1)
	{
		tokens = get_token(buff, delim);
		if (*buff == '\n' || *tokens == NULL)
		{
			free(tokens);
			if (isatty(STDIN_FILENO) == 1)
				prompt();

			continue;
		}
		handle_exit(tokens, buff);
		lunch(tokens);
		free(tokens);
		if (isatty(STDIN_FILENO) == 1)
			prompt();

	}
	free(buff);
	if (isatty(STDIN_FILENO) == 1)
		putchar('\n');
	return (0);
}
