/*
** exec2.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/execution
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:40:44 2014 chalie_a
** Last update Thu May  8 13:40:35 2014 chalie_a
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

extern int	g_exit;

void		cmd_not_in_paths(t_cmd *tmp, t_execution *exe) 
{
  if (tmp->stock[0] && !(strncmp(tmp->stock[0], "exit", 4)))
    g_exit = 42; 
  //_ERROR("Error : `%s' command not found\n", tmp->stock[0]);
  exe->return_value = 2;
  --(exe->nb_pipes);
}

int		execution_loop(t_cmd *cmd, t_execution *exe)
{
  t_cmd		*tmp;
  int		x;

  x = -1;
  tmp = cmd;
  exe->prev_pipe = -1;
  exe->fdp[0] = 0;
  exe->fdp[1] = 0;
  while ((tmp = tmp->next) != cmd)
    {
      exe->return_value = 0;
      if (!tmp->path)
	cmd_not_in_paths(tmp, exe);
      else if (/*printf("x = %d\n",x) && */ pipe(exe->fdp) != 42 && (exe->pid[++x] = fork()) == 0)
	{
	  if (tmp->next != cmd && dup2(exe->fdp[1], STDOUT_FILENO) < 0)
	    return (FAILURE);
	  if (exe->prev_pipe != -1 && dup2(exe->prev_pipe, STDIN_FILENO) < 0)
	    return (FAILURE);
	  if (tmp->next != cmd)
	    close(exe->fdp[0]);
	  execve(tmp->path, tmp->stock, exe->envp);
	  close(exe->fdp[1]);
	}
      else if (*exe->pid > 0)
	{
	  if (exe->prev_pipe != -1)
	    close(exe->prev_pipe);
	  if (tmp->next != cmd)
	    {
	      close(exe->fdp[1]);
	      exe->prev_pipe = exe->fdp[0];
	    }
	}
      else
	return (FAILURE);
    }
  return (SUCCESS);
}
