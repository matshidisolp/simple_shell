#include "main.h"


/**
  * _strdup - duplicates a string
  * @str: pointer to string
  * description: duplicates a string and returns a pointer to the new string
  * Return: pointer to new string
*/

char *_strdup(const char *str)
{
	int i, len;
	char *dup;

	if (str == NULL)
		return (NULL);

	len = _strlen_recursion(str);
	if (len  == 0)
		return (NULL);
	dup = malloc(sizeof(char) * len + 1);
	if (dup == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
	{
		dup[i] = str[i];
	}
	dup[i] = '\0';
	return (dup);
}
