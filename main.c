#include "main.h"
/**
  *main- driver function
  *Return: 0
  */
int main(void)
{
	ssize_t status;
	int i;
	size_t n;
	char *buff;
	char **tokens;

	status = 1;
	i = 0;
	while (status != -1)
	{
		i = 0;
		prompt();
		status = readline(&buff, &n);
		tokens = get_token(buff);
		while (tokens[i])
		{
			printf("%s\n", tokens[i]);
			i++;
		}
		free(tokens);
	}
	free(buff);
	return (0);
}
