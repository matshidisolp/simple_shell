#include  "main.h"

/**
  * get_token - gets tokens from string
  * @buff: pointer to string
  * @delim: pointer to string
  * desciption: gets tokens from a string using a specified delimeter
  * Return: array of strings or NULL
*/

char **get_token(char *buff, char *delim)
{
	int pos, buff_size, old_size;
	char *token;
	char **tokens;

	if (buff == NULL)
	{
		perror("./hsh");
		return (NULL);
	}
	if (*buff == '\n')
		return (NULL);
	pos = 0;
	buff_size = 64;
	tokens = malloc(sizeof(char *) * buff_size);
	if (tokens == NULL)
	{
		perror("./hsh");
		return (NULL);
	}
	token = strtok(buff, delim);
	while (token)
	{
		tokens[pos] = token;
		/*resize the tokens array if i have more than 64 tokens*/
		if (pos >= buff_size)
		{
			old_size = sizeof(char *) * buff_size;
			tokens = resize_buff(tokens, old_size);
			if (tokens == NULL)
			{
				perror("/hsh");
				return (NULL);
			}
			buff_size += buff_size;
		}
		token = strtok(NULL, delim);
		pos++;
	}
	tokens[pos] = NULL;
	return (tokens);
}
/**
  * resize_buff - resizes buffer
  * @buff: buffer to resize
  * @old_size: size of buffer
  * description: resizes the buffer pointer to by buff
  * Return: pointer to new buff
*/
char **resize_buff(char **buff, unsigned int old_size)
{
	unsigned int new_size;

	new_size = old_size * 2;
	buff = _realloc(buff, old_size, new_size);
	if (buff == NULL)
	{
		perror("./hsh");
		return (NULL);
	}
	return (buff);
}
