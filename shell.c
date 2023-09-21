#include "shell.h"

/**
 * x_prompt - function that will showed
 * to the user to enter commands
 *
 * Return: (void)
 */
void x_prompt(void)
{
	if (isatty(0))
		write(1, "shell$> ", 8);
}

/**
 * handle_sig - function that will be
 * passed to the signal to handle
 * ctrl-c
 *
 * @sig: signint signal number
 * Return: (void)
 */
void handle_sig(int sig)
{
	(void)sig;

	if (isatty(0))
		write(1, "\n$> ", 4);
}

/**
 * main - entry point to the program
 *
 * @ac: number of arguments
 * @av: arguments
 * Return: (0) success, otherwise error
 */
int main(int ac, char *av[])
{
	char *line, **tokens;
	size_t len;

	(void)ac;
	x_global_var(SET_PROGRAM_NAME, av[0]);
	signal(SIGINT, handle_sig);
	while (1)
	{
		line = NULL;
		x_prompt();
		if (getline(&line, &len, stdin) == -1)
		{
			free(line);
			break;
		}
		tokens = split_cmd(line, " \t\n");
		if (!tokens || !*tokens)
		{
			free(line);
			free(tokens);
			continue;
		}
		x_global_var(INCREMENT_LINE, NULL);
		if (!x_strcmp(tokens[0], "exit"))
		{
			free(line);
			free(tokens);
			x_exit();
		}
		else if (!x_strcmp(tokens[0], "env"))
			x_env();
		else
			execute_cmd(tokens);
		free(line);
		free(tokens);
	}
	return (x_status_track(GET_STATUS, 0));
}

