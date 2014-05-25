/*
** cd.c for Project-Master in /home/tovazm/rendu/42sh/42SH/builtins
** 
** Made by chalie_a
** Login   <abel.chalier@epitech.eu>
** 
** Started on  Tue May 20 10:03:48 2014 chalie_a
** Last update Thu May 22 23:13:58 2014 chalie_a
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "parser.h"
#include "sh.h"

static char		*get_current_dir(int cpt)
{
  char			*pwd;

  if (!(pwd = calloc(cpt, _MEM_POOL)))
    return (NULL);
  if (!(getcwd(pwd, cpt * _MEM_POOL)))
    {
      XFREE(pwd);
      return (errno == 34 ? get_current_dir(++cpt) : NULL);
    }
  return (pwd);
}

static int		actualise_pwd(t_execution *exe)
{
  char			*new_pwd;
  t_env_dll		*tmp;

  if (!(new_pwd = calloc(1, 1024)))
    return (B_FAILURE);
  if ((tmp = search_for_env_variable("PWD", exe->env->env_dll)))
    set_env_tech(exe, "OLDPWD", tmp->value);
  if (!(new_pwd = get_current_dir(1)))
    return (B_FAILURE);
  set_env_tech(exe, "PWD", new_pwd);
  return (B_SUCCESS);
}

int			change_dir(char *newdir, t_execution *exe)
{
  if (!(newdir))
    return (FAILURE);
  if ((access(newdir, F_OK | R_OK)) == -1)
    return (B_ERROR("%s\n", strerror(errno)));
  if (chdir(newdir) == FAILURE)
    return (B_ERROR("%s\n", strerror(errno)));
  return (actualise_pwd(exe));
}
