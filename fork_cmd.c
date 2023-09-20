#include "shell.h"

/**
 * fork_cmd - A function that creates a sub process.
 * @cmd: The pointer to tokenized command
 * @name: The pointer to the name of shell.
 * @env: The pointer to the enviromental variables.
 * @cycles: Number of executed cycles.
 * Return: Nothing.
 */
void fork_cmd(char **cmd, char *name, char **env, int cycles)
{
	int pid = 0;
	int status = 0;
	int wait_error = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		free_exit(cmd);
	}
	else if (pid == 0)
	{
		execute_cmd(cmd, name, env, cycles);
		free_cmd(cmd);
	}
	else
	{
		wait_error = waitpid(pid, &status, 0);
		if (wait_error < 0)
		{
			free_exit(cmd);
		}
		free_cmd(cmd);
	}
}
