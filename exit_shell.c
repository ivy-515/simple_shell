#include "shell.h"

/**
 * exit_shell - A function that exits the shell.
 * @cmd: The pointer to tokenized command.
 * Return: Nothing.
 */
void exit_shell(char **cmd) {
  int i = 0;

  if (cmd[1] == NULL) {
    free_cmd(cmd);
    exit(EXIT_SUCCESS);
  }

  i = x_atoi(cmd[1]);
  free_cmd(cmd);
  exit(i);
}
