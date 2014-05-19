/*
** main.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Thu Apr 17 23:43:50 2014 chalie_a
** Last update Mon May 19 14:11:22 2014 chalie_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "edit.h"
#include "sh.h"
#include "parser.h"
#include "my_color.h"
#include "tokenizer.h"


static void		free_exe(t_env_dll *root)
{
  t_env_dll		*tmp;
  t_env_dll		*save;

  if (!root)
    return ;
  save = root->prev;
  tmp = root;
  while ((tmp = tmp->next) != root)
    x_free(tmp->prev);
  x_free(save);
}

void			free_alias(t_alias *root)
{
  t_alias		*alias;
  t_alias		*save;

  save = root->prev;
  alias = root;
  while ((alias = alias->next) != root)
    {
      double_free(alias->prev->cmd);
      free(alias->prev);
    }
  double_free(save->cmd);
  free(save);
}

int			clean_all(t_shell *sh)
{
  int			i;
  int			exit_value;

  i = -1;
  exit_value = sh->exe->exit;
  free_exe(sh->exe->env->env_dll);
  free_alias(sh->alias);
  double_free(sh->hist_ign);
  double_free(sh->exe->env->paths);
  double_free(sh->exe->env->envp);
  free(sh->exe->env);
  free(sh->exe);
  free(sh);
  return (exit_value);
}
