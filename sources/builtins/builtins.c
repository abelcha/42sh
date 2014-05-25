/*
** builtins.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel.chalier@epitech.eu>
** 
** Started on  Thu May  8 23:49:35 2014 chalie_a
** Last update Sat May 24 18:33:21 2014 chalie_a
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "sh.h"

int			set_env_tech(t_execution *exe, char *s1, char *s2)
{
  t_env_dll		*tmp;
  char			*str;

  if (!(str = get_env_line(s1, s2)))
    return (B_FAILURE);
  if (!(tmp = search_for_env_variable(s1, exe->env->env_dll)))
    add_env_variable(exe->env->env_dll, str);
  else
    {
      XFREE(tmp->name);
      fill_env_struct(tmp, str);
    }
  put_env_in_tab(exe->env);
  if (!my_strncmp(str, "PATH=", 5))
    actualise_path(exe, str);
  return (B_SUCCESS);
}

int			my_setenv(t_execution *exe, t_cmd *cmd)
{
  if (!cmd->stock[1] || !cmd->stock[2] || cmd->stock[3])
    return (B_ERROR("Error, USAGE : setenv [Name] [Value]\n"));
  if (set_env_tech(exe, cmd->stock[1], cmd->stock[2]) == B_FAILURE)
    return (B_FAILURE);
  return (B_SUCCESS);
}

int			my_unsetenv(t_execution *exe, t_cmd *cmd)
{
  t_env_dll		*tmp;

  if (!cmd->stock[1] || cmd->stock[2])
    return (B_ERROR("Error, USAGE : setenv [Name]\n"));
  if (!(tmp = search_for_env_variable(cmd->stock[1], exe->env->env_dll)))
    return (B_ERROR("Error, Unkown variable `%s'\n", cmd->stock[1]));
  tmp->prev->next = tmp->next;
  tmp->next->prev = tmp->prev;
  XFREE(tmp->name);
  XFREE(tmp);
  put_env_in_tab(exe->env);
  if (!my_strncmp(cmd->stock[1], "PATH", 4))
    actualise_path(exe, NULL);
  return (B_SUCCESS);
}

int			my_exit(t_execution *exe, t_cmd *cmd)
{
  exe->exit = my_atoi(cmd->stock[1]) + 256;
  return (B_SUCCESS);
}
