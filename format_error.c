#include "main.h"

/**
 *format_error- formats error message and prints to stdout
 *@token: user string input
 *description: formats the error message to mimick Linux bash
 *Return: void
 */

int error_count = 0;

void format_error(const char *token)
{
	int i;
	ssize_t j;
	size_t msg_len, colon_len, token_len, not_fd_len, tot_len;
	ssize_t error_count_str_len;
	const char *shell = "./hsh: ";
	const char *colon = ": ";
	const char *not_fd = ": not found\n";
	char *ptr;
	char *total_error_msg;
	char error_count_buffer[20];

	error_count_str_len = int_to_string(error_count, error_count_buffer);
	msg_len = strlen(shell);
	colon_len = strlen(colon);
	token_len = strlen(token);
	not_fd_len = strlen(not_fd);
	tot_len = msg_len + error_count_str_len + colon_len + token_len + not_fd_len;
	total_error_msg = (char *)malloc(tot_len + 1);

	if (total_error_msg)
	{
		ptr = total_error_msg;
		for (i = 0; shell[i]; i++)
			*ptr++ = shell[i];
		for (j = 0; j < error_count_str_len; j++)
			*ptr++ = error_count_buffer[j];
		for (i = 0; colon[i]; i++)
			*ptr++ = colon[i];
		while (*token)
			*ptr++ = *token++;
		for (i = 0; not_fd[i]; i++)
			*ptr++ = not_fd[i];
		*ptr = '\0';
		write(STDERR_FILENO, total_error_msg, tot_len);
		free(total_error_msg);
	}
	error_count++;
}
