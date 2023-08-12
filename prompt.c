#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
  *print_str- prints a string
  *@str: pointer to string to be printed
  */
void print_str(char *str)
{
	while (*str)
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
}
/**
  *main- prompt user for a command and print it to stdout
  *
  *Return: command that user inputs
  */
int main(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t num_char = 1;
	char *prompt = "okimatshell$ ";

	while (num_char > 0)
	{
		print_str(prompt);
		num_char = getline(&lineptr, &n, stdin);
		if (num_char > 0)
		{
			lineptr[num_char - 1] = '\0';
			if (strcmp(lineptr, "exit") == 0)
				break;
			print_str(lineptr);
			print_str("\n");
		}
	}
	free(lineptr);
	return (0);
}
