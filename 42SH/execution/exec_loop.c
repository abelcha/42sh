/*
** exec2.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/execution
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:40:44 2014 chalie_a
** Last update Fri May 16 12:26:58 2014 chalie_a
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

static int	curr_pid;

int		cmd_not_in_paths(t_cmd *tmp, t_execution *exe) 
{
  _ERROR("Error : `%s' command not found\n", tmp->stock[0]);
  exe->return_value = 512;
  if (exe->prev_pipe != -1)
    close(exe->prev_pipe);
  if (exe->nb_pipes != exe->pos + 2)
    --(exe->exit);
  --(exe->nb_pipes);
  return (SUCCESS);
}


int		exec_in_father(t_cmd *root, t_cmd *tmp, t_execution *exe)
{
  setpgid(0, 0);
  if (!tmp->path && tmp->builtin == -1)
    return (cmd_not_in_paths(tmp, exe));
  if (tmp->next != root && dup2(exe->fdp[1], STDOUT_FILENO) < 0)
    return (FAILURE);
  if (exe->prev_pipe != -1 && dup2(exe->prev_pipe, STDIN_FILENO) < 0)
    return (FAILURE);
  if (tmp->next != root)
    close(exe->fdp[0]);
  if (tmp->builtin == -1)
   execve(tmp->path, tmp->stock, exe->env->envp);
  else
    {
      if (exe->nb_pipes != exe->pos + 2)
	handle_redirections(root, exe);
      exec_builtins(tmp, exe);
    }
  close(exe->fdp[1]);
  return (SUCCESS);
}


int		exec_in_son(t_cmd *root, t_cmd *tmp, t_execution *exe) 
{
  setpgid(curr_pid, curr_pid);
  if (exe->prev_pipe != -1)
    close(exe->prev_pipe);
  if (tmp->next != root)
    {
      close(exe->fdp[1]);
      exe->prev_pipe = exe->fdp[0];
    }
  return (SUCCESS);
}

int			exec_builtins(t_cmd *cmd, t_execution *exe)
{
  static const ptrft	b_tab[6] = {my_exit, my_setenv, my_unsetenv, my_cd,
				    my_env, my_echo};

  --(exe->nb_pipes);
  exe->return_value = b_tab[cmd->builtin](exe, cmd);
  if (cmd->builtin > 3 || exe->nb_pipes == exe->pos + 2)
    exe->exit = (exe->return_value == -1 ? 514 : 512);
  return (exe->return_value);
}

int		execution_loop(t_cmd *cmd, t_execution *exe)
{
  t_cmd		*tmp;

  tmp = cmd;
  exe->prev_pipe = -1;
  exe->pos = -1;
  if (handle_redirections(cmd, exe) == FAILURE)
    return (FAILURE);
  while ((tmp = tmp->next) != cmd && exe->exit == 0)
    {
      exe->return_value = 0;
      if (!tmp->path && tmp->builtin == -1 && exe->nb_pipes == exe->pos + 2)
	cmd_not_in_paths(tmp, exe);
      else if (tmp->builtin >= 0 && tmp->builtin < 4 && exe->nb_pipes == exe->pos + 2)
	exec_builtins(tmp, exe);
      else if (pipe(exe->fdp) != 42 && (curr_pid = fork()) == 0)
	exec_in_father(cmd, tmp, exe);
      else if (curr_pid > 0)
	exec_in_son(cmd, tmp, exe);
      else
	return (FAILURE);
      exe->pid[++exe->pos] = curr_pid;
    }
  close_redirections(cmd, exe);
  return (SUCCESS);
}
