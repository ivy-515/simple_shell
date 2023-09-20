#include "shell.h"

/**
 * free_cmd - A function that frees all the memory allocated for command.
 * @cmd: The pointer to allocated memory to free.
 * Return: Nothing.
 */
void free_cmd(char **cmd)
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
}
