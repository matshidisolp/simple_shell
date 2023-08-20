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

	delim = " \n";
	status = 0;
	do {
		prompt();
		status = readline(&buff, &n);
		tokens = get_token(buff, delim);
		lunch(tokens);
		free(tokens);
	} while (status != -1);
	free(buff);
	return (0);
}
