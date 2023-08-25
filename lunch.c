#include "main.h"
/**
  * lunch - executes command
  * @arg: tokens array
  * description: finds and executes commands
  * Return: Nothing
*/

void lunch(char **arg)
{
	int is_path, path_ext;
	char *cmd_path;
	char *cmd;

	if (arg == NULL)
		return;
	cmd = arg[0];
	if (_strcmp(cmd, "env") == 0)
	{
		printenv();
		return;
	}
	is_path = if_path(cmd);
	if (is_path == 0)
	{
		path_ext = find_path(cmd);
		if (path_ext == 0)
		{
			executor(arg);
		}
		else
      format_error(cmd);
	else
	{
		cmd_path = build_path(cmd);
		if (cmd_path != NULL)
		{
			arg[0] = cmd_path;
			executor(arg);
			free(cmd_path);
		}
		else
			format_error(cmd);
	}
}
