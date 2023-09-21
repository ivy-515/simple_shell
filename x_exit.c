#include "shell.h"

/**
 * x_exit - function that help to
 * exit from the program with the
 * status of the last command
 * executed
 *
 * Return: (void)
 */
void x_exit(void)
{
	_exit(x_status_track(GET_STATUS, 0));
}

