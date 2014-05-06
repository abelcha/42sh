/*
** exec2.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/execution
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:40:44 2014 chalie_a
** Last update Tue May  6 17:16:12 2014 chalie_a
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
  t_cmd		*tmp;
  int		pipefd[2];
  int		prevpipe;

  tmp = cmd;
  prevpipe = -1;
  while ((tmp = tmp->next) != cmd)
    {
      if (tmp->next != cmd)
	pipe(pipefd);
      if ((*pid = fork()) == 0)
	{
	  if (tmp->next != cmd && dup2(pipefd[1], STDOUT_FILENO) < 0)
	    return (FAILURE);
	  if (prevpipe != -1 && dup2(prevpipe, STDIN_FILENO) < 0)
	    return (FAILURE);
	  execve(tmp->path, tmp->stock, envp);
	  close(pipefd[1]);
	  return (FAILURE);
	}
      else if (*pid > 0)
	{
	  if (prevpipe != -1)
	    close(prevpipe);
	  if (tmp->next != cmd)
	    {
	      close(pipefd[1]);
	      prevpipe = pipefd[0];
	    }
	}
      else
	return (FAILURE);
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
  exec_each_pipe(cmd, num_pipes, pipefds, pid);
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
