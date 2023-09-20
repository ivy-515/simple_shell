#include "shell.h"

/**
 * main - A function that runs the shell.
 * @argc: The number of arguments.
 * @argv: The pointer to array of arguments.
 * @envir: The pointer to array of enviromental variables.
 * Return: Always 0.
 */
int main(int argc, char **argv, char **envir)
{
	char *buffer = NULL, **cmd = NULL;
	size_t buf_size = 0;
	ssize_t line = 0;
	int cycles = 0;
	(void)argc;

	while (1)
	{
		cycles++;
		x_prompt();
		signal(SIGINT, x_signal);
		line = getline(&buffer, &buf_size, stdin);
		if (line == EOF)
			x_EOF(buffer);
		else if (*buffer == '\n')
			free(buffer);
		else
		{
			buffer[x_strlen(buffer) - 1] = '\0';
			cmd = split_cmd(buffer, " \0");
			free(buffer);
			if (x_strcmp(cmd[0], "exit") != 0)
				exit_shell(cmd);
			else if (x_strcmp(cmd[0], "cd") != 0)
				x_cd(cmd[1]);
			else
				fork_cmd(cmd, argv[0], envir, cycles);
		}
		fflush(stdin);
		buffer = NULL, buf_size = 0;
	}
	if (line == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
