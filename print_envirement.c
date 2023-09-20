#include "shell.h"

/**
 * print_envirement - A function that prints all enviromental variables.
 * @envi: The pointer to enviromental variables.
 * Return: Nothing.
 */
void print_envirement(char **envi)
{
	size_t i = 0, len = 0;

	while (envi[i])
	{
		len = x_strlen(envi[i]);
		write(STDOUT_FILENO, envi[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
