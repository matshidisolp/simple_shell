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
			printf("%s\n", cmd);
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
			printf("%s\n", cmd_path);
			free(cmd_path);
		}
		else
		{
			/*handle error*/
			perror("./hsh");
		}
	}
}

/**
  * find_path - finds a file path
  * @cmd: tokens array
  * description: finds and executes commands
  * Return: 1(success) -1(failure);
*/
int find_path(char *cmd)
{
	int path_exst;

	if (cmd == NULL)
		return (-1);

	path_exst = stat(cmd, &info);
	if (path_exst == 0)
		return (0);
	else
		return (-1);
}

/**
  * if_path - checks if a full path was given
  * @cmd: command
  * description: checks if a path was provided
  * Return: 1(success) -1(failure)
*/

int if_path(char *cmd)
{
	while (*cmd)
	{
		if (*cmd == '/')
			return (0);
		cmd++;
	}
	return (-1);
}
/**
  * build_path - builds a path to regular cmd
  * @cmd: command
  * description: builds path to a command
  * Return: 1(success) -1(failure)
*/
char *build_path(char *cmd)
{
	char *path_evn, *path_cpy, *cmd_path;
	char **dirs;
	int path_exst, i;

	path_evn = _getenv("PATH");
	path_cpy = _strdup(path_evn);
	dirs = get_token(path_cpy, ":");
	i = 0;
	while (dirs[i])
	{
		cmd_path = malloc(sizeof(char) * 4096);
			if (cmd_path == NULL)
			{
				free(dirs);
				free(path_cpy);
				return (NULL);
			}
		_strcpy(cmd_path, dirs[i]);
		_strcat(cmd_path, "/");
		_strcat(cmd_path, cmd);
		path_exst = stat(cmd_path, &info);
		if (path_exst == 0)
		{
			free(dirs);
			free(path_cpy);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free(path_cpy);
	free(dirs);
	return (NULL);
}
