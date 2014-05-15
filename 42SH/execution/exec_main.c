/*
** exec2.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/execution
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:40:44 2014 chalie_a
** Last update Thu May 15 17:16:50 2014 chalie_a
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


static const char	*sig_tab[11] = {"Hangup",
					"SIGINT",
					"Quit",
					"Illegal instruction)",
					"Trace/breakpoint trap",
					"Aborted", 
					"Bus Error",
					"Floating point exception",
					"Killed",
					" ",
					"Segmentation Fault"};

int		wait_pipes(t_execution *exe)
{
  int		i;
  int		status;
  int		ret;

  i = -1;
  while (++i < exe->nb_pipes)
    {
      ret = waitpid(exe->pid[i], &status, 0);
      if (!exe->return_value)
	exe->return_value = WEXITSTATUS(status);
    }
  if(status < 1000 && WIFSIGNALED(status))
    {
      if(WTERMSIG(status) < 13)
	printf("%s", sig_tab[(WTERMSIG(status) - 1) % 13]);
      printf(WCOREDUMP(status) ? " (Core Dumped)\n" : "\n");
    }
  return (SUCCESS);
}


int		exec(t_cmd *cmd, t_execution *exe)
{
  if (!(exe->pid = calloc(exe->nb_pipes, sizeof(int *))))
    return (FAILURE);
  execution_loop(cmd, exe);
  printf("background = %d\n", cmd->prev->background);
  if (exe->nb_pipes > 0 && !exe->exit && !(cmd->prev->background))
    wait_pipes(exe);
  free(exe->pid);
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
	  {
	    exec(tmp->cmd, exe);
	    // printf(exe->return_value ? "\033[31mfailure %d\n" :
	    //		   "\033[32msuccess %d\n", exe->return_value);
	    RST;
	  }
    }
  return (SUCCESS);
}
