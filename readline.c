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

	if (buff == NULL || n == NULL)
		return (-1);
	bytes_read = getline(buff, n, stdin);
	if (bytes_read == -1)
		return (-1);
	else
		return (bytes_read);
}

