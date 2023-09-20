#include "shell.h"

/**
 * free_exit - A function that frees all the memory allocated and exit.
 * @cmd: The pointer to allocated command memory to free.
 * Return: Nothing.
 */
void free_exit(char **cmd)
{
	size_t i = 0;

	if (cmd == NULL)
		return;

	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}

	if (cmd[i] == NULL)
		free(cmd[i]);
	free(cmd);
	exit(EXIT_FAILURE);
}
