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

	/*check if command is a path or regular command*/
	if (arg == NULL)
		return;
	cmd = arg[0];
	is_path = if_path(cmd);
	if (is_path == 0)
	{
		/*check if path exist*/
		path_ext = find_path(cmd);
		if (path_ext == 0)
		{
			/*fork and execute*/
			executor(arg);
		}
		else
		{
			/*handle error;*/
			perror("./hsh");
		}
	}
	else
	{
		cmd_path = build_path(cmd);
		if (cmd_path != NULL)
		{
			/*fork and execute*/
			arg[0] = cmd_path;
			executor(arg);
			free(cmd_path);
		}
		else
		{
			/*handle error*/
			perror("./hsh");
		}
	}
}

