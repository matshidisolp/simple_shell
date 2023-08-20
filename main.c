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
		handle_exit(tokens);
		executor(tokens);
		lunch(tokens);
<<<<<<< HEAD
		/*executor(tokens);*/
=======
>>>>>>> 32855b18f99b1de3e5058be926ac2cd9c19601f6
		free(tokens);
	} while (status != -1);
	free(buff);
	return (0);
}
