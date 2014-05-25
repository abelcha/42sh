/*
** main.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel.chalier@epitech.eu>
** 
** Started on  Thu Apr 17 23:43:50 2014 chalie_a
** Last update Fri May 23 12:37:24 2014 chalie_a
*/

#include "sh.h"

static void		free_exe(t_env_dll *root)
{
  t_env_dll		*tmp;
  t_env_dll		*save;

  if (!root)
    return ;
  save = root->prev;
  tmp = root;
  while ((tmp = tmp->next) != root)
    XFREE(tmp->prev);
  XFREE(save);
}

void			free_alias(t_alias *root)
{
  t_alias		*alias;
  t_alias		*save;

  save = root->prev;
  alias = root;
  while ((alias = alias->next) != root)
    {
      double_free(&alias->prev->cmd);
      XFREE(alias->prev);
    }
  double_free(&save->cmd);
  XFREE(save);
}

int			clean_all(t_shell *sh)
{
  int			exit_value;

  exit_value = sh->exe->exit;
  free_exe(sh->exe->env->env_dll);
  free_alias(sh->alias);
  double_free(&sh->hist_ign);
  double_free(&sh->exe->env->paths);
  double_free(&sh->exe->env->envp);
  XFREE(sh->exe->env);
  XFREE(sh->exe);
  XFREE(sh);
  return (exit_value);
}
