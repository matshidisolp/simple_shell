#include "main.h"
/**
  * printenv - print current enviroment
  * description: prints the program enviroment variable
  * Return: nothing
*/
void printenv(void)
{
	int i, j;

	i = 0;
	j = 0;
	while (environ[i] != NULL)
	{
		j = 0;

		while (environ[i][j] != '\0')
		{
			_putchar(environ[i][j]);
			j++;
		}
		_putchar('\n');
		i++;
	}
}
