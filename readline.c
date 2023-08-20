#include "main.h"
/**
  * readline - gets input and tokenize by a delimeter
  * @buff: buffer to store the tokens gotten
  * @n: size of buffer
  * description: reads a  line fro stdin and tokenize by space
  * Return: array of tokens or NULL
*/


ssize_t readline(char **buff, size_t *n)
{
	ssize_t bytes_read;

	bytes_read = getline(buff, n, stdin);
	if (bytes_read == -1)
	{
		if (isatty(fileno(stdin)))
		{
			/*Check for EOF (Ctrl+D)*/
			free(*buff);
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}
	return (bytes_read);
}
