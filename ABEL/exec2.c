/*
** exec2.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/execution
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:40:44 2014 chalie_a
** Last update Tue May  6 15:46:26 2014 chalie_a
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include "sh.h"
#include "parser.h"

extern char	**envp;
int		return_value;

static const char	*sig_tab[11] = {"Hangup",
					"^C",
					"Quit",
					"Illegal instruction)",
					"Trace/breakpoint trap",
					"Aborted", 
					"Bus Error",
					"Floating point exception",
					"Killed",
					" ",
					"Segmentation Fault"};

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
    {
      if (pipe(&pipes[i * 2]) < 0)
	return (FAILURE);
    }
  return (SUCCESS);
}

int		signal_ctz(int sig)
{
  printf("Error Wait Failed");
  exit(FAILURE);
  return (sig);
}

int		wait_pipes(int pipe_nbr, int *pid)
{
  int		i;
  int		status;
  int		ret;

  i = -1;
  while (++i < pipe_nbr + 1)
    {
      ret = waitpid(pid[i], &status, 0);
      return_value = WEXITSTATUS(status);
    }
  if(WIFSIGNALED(status))
    printf("%s (Core Dumped)\n", sig_tab[(WTERMSIG(status) - 1) % 13]);
  return (SUCCESS);
}

int		exec_each_pipe(t_cmd *cmd, int num_pipes, int *pipefds, int *pid)
{
  int		j;
  t_cmd		*tmp;

  tmp = cmd;
  j = 0;
  while ((tmp = tmp->next) != cmd)
    {
      if ((*pid = fork())== 0)
	{
	  if (tmp->next != cmd && ((dup2(pipefds[j + 1], STDOUT_FILENO)) < 0))
	    return (FAILURE);
	  if (j != 0 && ((dup2(pipefds[j - 2], STDIN_FILENO) < 0)))
	    return (FAILURE);
	  close_pipes(pipefds, num_pipes * 2);
	  execve(tmp->path, tmp->stock, envp);
	}
      j += 2;
      ++pid;
    }
  return (SUCCESS);
}

int		exec(t_cmd *cmd, int num_pipes)
{
  int		*pipefds;
  int		pid[42];
  
  memset(pid, 0, 42);
  if (!(pipefds = calloc(2 * num_pipes, sizeof(int))))
    return (FAILURE);
  do_pipes(pipefds, num_pipes);
  exec_each_pipe(cmd, num_pipes, pipefds, pid);
  close_pipes(pipefds, num_pipes * 2);
  wait_pipes(num_pipes, pid);
  free(pipefds);
  return (SUCCESS);
}

int		exec_cmd(t_parse_tree *root)
{
  t_parse_tree	*tmp;

  return_value = 0;
  tmp = root;
  while ((tmp = tmp->next) != root)
    {
      if (tmp->cmd->next->stock[0])
	if (tmp->prev->token == 0 ||
	    tmp->token == T_SEM ||
	    (tmp->token == T_AND && return_value == 0) ||
	    (tmp->token == T_OR && return_value > 0))
	  exec(tmp->cmd, tmp->nb_pipes + 1);
    }
  return (SUCCESS);
}
