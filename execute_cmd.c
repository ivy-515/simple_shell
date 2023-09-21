#include "shell.h"

/**
 * x_get_path - function that looks for
 * path in the valid path
 *
 * Return: void
 */
char *x_get_path(void)
{
	char *path, *line;
	char **envirs, **chunks;

	envirs = __environ;
	while (*envirs)
	{
		line = x_strdup(*envirs);
		chunks = split_cmd(line, "=");
		if (!x_strcmp(chunks[0], "PATH"))
		{
			path = x_strdup(chunks[1]);
			free(line);
			free(chunks);
			return (path);
		}
		free(line);
		free(chunks);
		envirs++;
	}
	return (NULL);
}

/**
 * get_cmd_path - function that get
 * command concatenated with the path
 *
 * @cmd_name: command name
 * Return: command
 */
char *get_cmd_path(char *cmd_name)
{
	char *path, **path2d, **iterator, dest[200];
	struct stat st;

	if ((cmd_name[0] == '.' ||
		 cmd_name[0] == '/') &&
		!stat(cmd_name, &st))
	{
		return (x_strdup(cmd_name));
	}
	path = x_get_path();
	if (!path)
		return (NULL);
	path2d = iterator = split_cmd(path, ":");
	while (*iterator)
	{
		dest[0] = 0;
		x_strcat(x_strcat(x_strcat(dest, *iterator), "/"), cmd_name);
		if (!stat(dest, &st))
		{
			free(path);
			free(path2d);
			return (x_strdup(dest));
		}
		iterator++;
	}
	free(path);
	free(path2d);
	return (NULL);
}

/**
 * execute_cmd - function that executes
 * given command
 *
 * @tokens: 2d array contain command
 * information
 * Return: (void)
 */
void execute_cmd(char **tokens)
{
	char *command_with_path;
	int pid, status;

	command_with_path = get_cmd_path(tokens[0]);
	if (!command_with_path)
	{
		x_format_printf(2, "%s: %d: %s: not found\n",
				 (char *)x_global_var(GET_PROGRAM_NAME, NULL),
				 *((int *)x_global_var(GET_LINE_NUMBER, NULL)),
				 tokens[0]);
		x_status_track(UPDATE_STATUS, 127);
		return;
	}
	pid = fork();
	if (pid < 0)
	{
		perror("$");
		x_status_track(UPDATE_STATUS, 1);
		return;
	}
	else if (pid == 0)
	{
		execve(command_with_path, tokens, __environ);
		free(command_with_path);
		free(tokens);
		perror("$");
		if (errno == EACCES)
			_exit(126);
		exit(errno);
	}
	else
	{
		wait(&status);
		x_status_track(UPDATE_STATUS, WEXITSTATUS(status));
		free(command_with_path);
	}
}

