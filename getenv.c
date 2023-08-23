#include "main.h"
/**
  * _getenv - gets an enviroment variable
  * @name: environment variable
  * description: gets the envirmonment varible specified by name
  * Return: pointer to environment or NULL failure
*/

char *_getenv(const char *name)
{
	int i, len;
	char *curr_env_cpy, *token;
	/*check if environ is null*/
	len = _strlen_recursion(name);
	i = 0;
	while (environ[i])
	{
		curr_env_cpy = _strdup(environ[i]);
		token = strtok(curr_env_cpy, "=");
		if (_strcmp(token, name) == 0)
		{
			free(curr_env_cpy);
			return (&(environ[i][len + 1]));
		}
		free(curr_env_cpy);
		i++;
	}
	return (NULL);
}
