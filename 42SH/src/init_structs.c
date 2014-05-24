/*
** main.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel.chalier@epitech.eu>
** 
** Started on  Thu Apr 17 23:43:50 2014 chalie_a
** Last update Sat May 24 18:09:30 2014 chalie_a
*/

#include <stdlib.h>
#include <unistd.h>
#include "edit.h"
#include "sh.h"

static t_execution		*init_exe(char **env)
{
  t_execution			*exe;

  if (!(exe = calloc(1, sizeof(t_execution))))
    return (NULL);
  if (!(exe->env = calloc(1, sizeof(t_env))))
    return (NULL);
  if (put_env_in_dll(env, exe) == FAILURE)
    return (NULL);
  if (!(exe->env->paths = get_paths(get_env(env, "PATH="), ':')))
    return (NULL);
  exe->input = isatty(0);
  return (exe);
}

static t_line			*init_sline()
{
  t_line			*line;

  if (!(line = calloc(1, sizeof(t_line))))
    return (NULL);
  return (line);
}

static t_alias			*init_alias()
{
  t_alias			*root;

  if (!(root = calloc(1, sizeof(t_alias))))
    return (NULL);
  root->prev = root;
  root->next = root;
  return (root);
}

t_shell				*init_sh(char **env)
{
  t_shell			*sh;

  if (!(sh = calloc(1, sizeof(t_shell))))
    return (NULL);
  if (!(sh->line = init_sline()))
    return (NULL);
  sh->line->sh = sh;
  if (!(sh->exe = init_exe(env)))
    return (NULL);
  sh->exe->sh = sh;
  if (!(sh->alias = init_alias()))
    return (NULL);
  if (init_history(sh->line) == FAILURE)
    return (NULL);
  return (sh);
}
