#include "shell.h"

/**
 * x_prompt - A function that prints the prompt
 * Return: Nothing.
 */
void x_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "Shell$ ", 7);
}
