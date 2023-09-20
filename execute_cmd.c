#include "shell.h"

/**
 * execute_cmd - A function that executes a command.
 * @cmd: The pointer to tokienized command
 * @name: The name of the shell.
 * @env: The pointer to the enviromental variables.
 * @cycles: Number of executed cycles.
 * Return: Nothing.
 */
void execute_cmd(char **cmd, char *name, char **env, int cycles) {
  char **pathways = NULL, *full_path = NULL;
  struct stat st;
  unsigned int i = 0;

  if (x_strcmp(cmd[0], "env") != 0)
    print_envirement(env);
  if (stat(cmd[0], &st) == 0) {
    if (execve(cmd[0], cmd, env) < 0) {
      perror(name);
      free_exit(cmd);
    }
  } else {
    pathways = x_getPATH(env);
    while (pathways[i]) {
      full_path = x_strcat(pathways[i], cmd[0]);
      i++;
      if (stat(full_path, &st) == 0) {
        if (execve(full_path, cmd, env) < 0) {
          perror(name);
          free_cmd(pathways);
          free_exit(cmd);
        }
        return;
      }
    }
    print_nfound(name, cycles, cmd);
    free_cmd(pathways);
  }
}
