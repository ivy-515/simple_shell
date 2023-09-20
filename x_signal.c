i#include "shell.h"

/**
 * x_signal - A function to handle Ctr + C signal.
 * @signals: The signal to handle.
 * Return: Nothing.
 */
void x_signal(int signals)
{
	(void)signals;
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "\nShell$ ", 8);
}
