#include "shell.h"

/**
 * print_nfound - A function that prints message not found.
 * @name: The name of the shell.
 * @cycles: Number of cicles.
 * @cmd: The pointer to tokenized command.
 * Return: Nothing.
 */
void print_nfound(char *name, int cycles, char **cmd) {
  char c;

  c = cycles + '0';
  write(STDOUT_FILENO, name, x_strlen(name));
  write(STDOUT_FILENO, ": ", 2);
  write(STDOUT_FILENO, &c, 1);
  write(STDOUT_FILENO, ": ", 2);
  write(STDOUT_FILENO, cmd[0], x_strlen(cmd[0]));
  write(STDOUT_FILENO, ": not found\n", 12);
}
