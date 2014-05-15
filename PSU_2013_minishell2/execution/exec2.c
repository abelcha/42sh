/*
** exec2.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/execution
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:40:44 2014 chalie_a
** Last update Mon May  5 11:21:11 2014 chalie_a
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

/*
cmd0    cmd1   cmd2   cmd3   cmd4
   pipe0   pipe1  pipe2  pipe3
   [0,1]   [2,3]  [4,5]  [6,7]
*/

int		signal_ctz(int sig)
{
  my_puterr("Error Wait Failed");
  exit(FAILURE);
  return (sig);
}

int		wait_pipes(int pipe_nbr)
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
  pid_t		pid;
  int		x;
  int		*pipefds;
  int		j;

  j = -2;
  x = -1;
  pid = 0;
  if (!(pipefds = x_calloc(2 * num_pipes, sizeof(int))))
    return (FAILURE);
  do_pipes(pipefds, num_pipes);
  while (stock[++x] && (pid = fork()) >= 0)
    if (++j && j++ && pid == 0)
      {
	//signal(SIGINT, (__sighandler_t) signal_ctz);
	if (stock[x + 1] && ((dup2(pipefds[j + 1], STDOUT_FILENO)) < 0))
	  return (FAILURE);
	if (j != 0 && ((dup2(pipefds[j - 2], STDIN_FILENO) < 0)))
	  return (FAILURE);
	close_pipes(pipefds, num_pipes * 2);
	execvp(stock[x][0], stock[x]);
	//        exec_command(path, stock[x], env);
      }
  close_pipes(pipefds, num_pipes * 2);
  wait_pipes(num_pipes);
  return (SUCCESS);
}
