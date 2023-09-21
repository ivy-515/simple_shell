#include "shell.h"

/**
 * x_env - function that prints
 * what inside the environment
 *
 * Return: void
 */
void x_env(void)
{
	char **envirements;

	envirements = __environ;
	while (*envirements)
	{
		printf("%s\n", *envirements);
		envirements++;
	}
}

