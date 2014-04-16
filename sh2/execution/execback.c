/*
** exec2.c for sh in /home/tovazm/rendu/sh/execution
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Mar  9 16:24:57 2014 chalie_a
** Last update Sun Mar  9 16:28:27 2014 chalie_a
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include "mysh.h"

static void	close_pipes(int *pipes, int pipe_nbr)
{
  int		i;

  i = -1;
  while (++i < pipe_nbr)
    close(pipes[i]);
}

int		do_pipes(int *pipes, int pipe_nbr)
{
  int		i;

  i = -1;
  while (++i < pipe_nbr)
    if (pipe(&pipes[i * 2]) < 0)
      return (FAILURE);
  return (SUCCESS);
}

int		signal_ctz(int sig)
{
  my_puterr("Error : Wait Failed");
  exit(FAILURE);
}

int		wait_pipes(int *pipes, int pipe_nbr)
{
  int		i;
  int		status;

  i = -1;
  while (++i < pipe_nbr + 1)
    if (wait(&status) == -1)
      return (FAILURE);
  return (SUCCESS);
}

int		exec_pipe(char ***stock, int num_pipes, char **path, char **env)
{
  int		x;
  int		j;
  int		pid;
  int		*pipefds;

  j = -2;
  x = -1;
  if (!(pipefds = calloc(2 * num_pipes, sizeof(int))))
    return (FAILURE);
  do_pipes(pipefds, num_pipes);
  while (stock[++x] && (pid = fork()) >= 0)
    if (pid == 0)
      {
	j = j + 2;
	signal(SIGINT, (__sighandler_t) signal_ctz);
	if (stock[x + 1] && ((dup2(pipefds[j + 1], STDOUT_FILENO)) < 0))
	  return (FAILURE);
	if (j != 0 && ((dup2(pipefds[j - 2], STDIN_FILENO) < 0)))
	  return (FAILURE);
	close_pipes(pipefds, num_pipes * 2);
        exec_command(path, stock[x], env);
      }
  close_pipes(pipefds, num_pipes * 2);
  wait_pipes(pipefds, num_pipes);
  return (SUCCESS);
}
