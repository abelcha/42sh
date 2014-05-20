/*
** builtins.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Thu May  8 23:49:35 2014 chalie_a
** Last update Tue May 20 10:59:59 2014 chalie_a
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "parser.h"
#include "sh.h"

#define B_SUCCESS	0
#define B_FAILURE	2

int		my_exit(t_execution *exe, t_cmd *cmd)
{
  exe->exit = my_atoi(cmd->stock[1]) + 256;
  return (B_SUCCESS);
}

int		set_env_tech(t_execution *exe, char *s1, char *s2)
{
  t_env_dll	*tmp;
  char		*str;

  if (!(str = get_env_line(s1, s2)))
    return (B_FAILURE);
  if (!(tmp = search_for_env_variable(s1, exe->env->env_dll)))
    add_env_variable(exe->env->env_dll, str);
  else
    {
      free(tmp->name);
      fill_env_struct(tmp, str);
    }
  put_env_in_tab(exe->env);
  if (!strncmp(str, "PATH=", 5))
    actualise_path(exe, str);
  return (B_SUCCESS);
}

int		my_setenv(t_execution *exe, t_cmd *cmd)
{
  if (!cmd->stock[1] || !cmd->stock[2] || cmd->stock[3])
    return (_ERROR("Error, USAGE : setenv [Name] [Value]\n"));
  if (set_env_tech(exe, cmd->stock[1], cmd->stock[2]) == B_FAILURE)
    return (B_FAILURE);
  return (B_SUCCESS);
}

int		my_unsetenv(t_execution *exe, t_cmd *cmd)
{
  t_env_dll	*tmp;

  if (!cmd->stock[1] || cmd->stock[2])
    return (_ERROR("Error, USAGE : setenv [Name]\n"));
  if (!(tmp = search_for_env_variable(cmd->stock[1], exe->env->env_dll)))
    return (_ERROR("Error, Unkown variable `%s'\n", cmd->stock[1]));
  tmp->prev->next = tmp->next;
  tmp->next->prev = tmp->prev;
  x_free(tmp->name);
  x_free(tmp);
  put_env_in_tab(exe->env);
  if (!strncmp(cmd->stock[1], "PATH", 4))
    actualise_path(exe, NULL);
  return (B_SUCCESS);
}

int		my_echo(t_execution *exe, t_cmd *cmd)
{
  char		flagstatus[2];

  (void)exe;
  flagstatus[0] = 0;
  flagstatus[1] = 0;
  find_flags(cmd->stock, flagstatus);
  find_strings(cmd->stock, flagstatus);
  return (B_SUCCESS);
}

