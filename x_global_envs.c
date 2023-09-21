#include "shell.h"

/**
 * x_global_var - function that helps
 * to access global variables everywhere
 * in the program
 *
 * @action: to be applied to the global variables
 * @s: to be assigned to program name
 * on the actions
 * Return: (void *)
 */
void *x_global_var(global_action_t action, char *s)
{
	static int line;
	static char *prg_name;

	if (action == SET_PROGRAM_NAME)
		prg_name = s;
	if (action == GET_PROGRAM_NAME)
		return (prg_name);
	if (action == INCREMENT_LINE)
		line++;
	if (action == GET_LINE_NUMBER)
		return (&line);
	return (NULL);
}
