/*
** exec2.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/execution
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:40:44 2014 chalie_a
** Last update Tue May 20 18:29:33 2014 chalie_a
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


static void		launch_in_background(t_execution *exe)
{
  t_jobs		*newelem;
  t_jobs		*tmp;

  setpgid(exe->curr_pid, exe->curr_pid);
  if (!(newelem = calloc(1, sizeof(t_jobs))))
    return ;
  if (!(newelem->cmd = my_strdup(exe->sh->line->line)))
    return ;
  newelem->prev = exe->sh->jobs->prev;
  newelem->next = exe->sh->jobs;
  exe->sh->jobs->prev->next = newelem;
  exe->sh->jobs->prev = newelem;
  tmp = exe->sh->jobs;
  newelem->pid = exe->curr_pid;
  while ((tmp = tmp->next) != exe->sh->jobs)
    ++(newelem->nbr);
}

static void		print_jobs(t_jobs *jobs)
{
  t_jobs		*tmp;

  tmp = jobs;
  while ((tmp = tmp->next) != jobs)
    printf("curr pid = %d -- CMD = '%s'\n", tmp->pid, tmp->cmd);
}

static int		wait_pipes(t_execution *exe)
{
  int			i;
  int			status;

  i = -1;
  while (++i < exe->nb_pipes)
    {
      waitpid(exe->pid[i], &status, 0);
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
    launch_in_background(exe);
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
  print_jobs(exe->sh->jobs);
  return (SUCCESS);
}
