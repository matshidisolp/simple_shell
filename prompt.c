#include "main.h"

/**
  *prompt- prints a string
  *Description: function prints a prompt to stdout
  *Return:
  */
void prompt(void)
{
	char *str = "okimatshell$ ";

	while (*str)
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
}
