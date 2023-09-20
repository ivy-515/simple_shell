#include "shell.h"

/**
 * x_strlen - A function that finds the length of the string
 * @s: The input string
 * Return: The length of the string
 */
unsigned int x_strlen(char *s)
{
	unsigned int len = 0;

	while (s[len])
		len++;

	return (len);
}
