/*
** exec2.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/execution
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:40:44 2014 chalie_a
** Last update Sun May 18 12:28:34 2014 chalie_a
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
#include "my_color.h"

static const char	*g_sig_tab[11] = {
  "Hangup",
  "",
  "Quit",
  "Illegal instruction)",
  "Trace/breakpoint trap",
  "Aborted",
  "Bus Error",
  "Floating point exception",
  "",
  "",
  "Segmentation Fault"};

static int		wait_pipes(t_execution *exe)
{
  int			i;
  int			status;
  int			ret;

  i = -1;
  while (++i < exe->nb_pipes)
    {
      ret = waitpid(exe->pid[i], &status, 0);
      if (!exe->return_value)
	exe->return_value = WEXITSTATUS(status);
    }
  if (status < 1000 && WIFSIGNALED(status))
    {
      exe->return_value = status; 
      if (WTERMSIG(status) < 13)
	printf("%s", g_sig_tab[(WTERMSIG(status) - 1) % 11]);
      printf(WCOREDUMP(status) ? " (Core Dumped)\n" : "\n");
    }
  return (SUCCESS);
}

int			exec(t_cmd *cmd, t_execution *exe)
{
  exe->prev_pipe = -1;
  exe->pos = -1;
  if (!(exe->pid = calloc(exe->nb_pipes, sizeof(int *))))
    return (FAILURE);
  execution_loop(cmd, exe);
  if (cmd->prev->background && !exe->return_value)
    setpgid(exe->curr_pid, exe->curr_pid);
  else if (exe->nb_pipes > 0 && !exe->exit)
  wait_pipes(exe);
  free(exe->pid);
  exe->pid = NULL;
  return (SUCCESS);
}

int		exec_cmd(t_parse_tree *root, t_execution *exe)
{
  t_parse_tree	*tmp;

  exe->return_value = 0;
  tmp = root;
  while ((tmp = tmp->next) != root && exe->exit == 0)
    {
      exe->nb_pipes = tmp->nb_pipes + 1;
      if (tmp->cmd->next->stock[0])
	if (tmp->prev->token == 0 ||
	    tmp->token == T_SEM ||
	    (tmp->token == T_AND && exe->return_value == 0) ||
	    (tmp->token == T_OR && exe->return_value > 0))
	  exec(tmp->cmd, exe);
    }
  return (SUCCESS);
}
