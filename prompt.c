#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

/**
  *print_str- prints a string
  *@str: pointer to string to be printed
  *
  *Return: the string
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
	char *lineptr;
	size_t n;
	ssize_t num_char;
	char *prompt = "okmatshell$ ";

	while (num_char > 0)
	{
		print_str(prompt);
		num_char = getline(&lineptr, &n, stdin);
		print_str(lineptr);
	}
	return (0);
}
