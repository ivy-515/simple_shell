#include "shell.h"

#define MAX_INPUT_SIZE 1024

/**
 * x_getline - reads input to buffer
 * static - stores data
 * @buffer - stores input
 * @size - a measure of input
 * @stdin - standard input
 * Return: results
*/
char *x_getline()
{
	static char ipt_buffer[MAX_INPUT_SIZE];

	char *result = fgets(ipt_buffer, MAX_INPUT_SIZE, stdin);

	if (result != NULL)
	{
		char *newline_position = strchr(ipt_buffer, '\n');

		if (newline_position != NULL)
			*newline_position = '\0';
	}

	return (result);
}
