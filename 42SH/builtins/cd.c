/*
** cd.c for 42sh in /home/coutar_a/rendu/42sh/42SH/builtins
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Sat May 17 14:24:19 2014 coutar_a
** Last update Mon May 19 20:45:13 2014 coutar_a
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "sh.h"

int		cd_home(t_execution *exe, t_cmd *cmd)
{
  char		*oldpwd;
  char		*pwd;
  t_env_dll	*tmp;
  t_env_dll	*tmp2;

  (void)cmd;
  if (!(tmp = search_for_env_variable("HOME", exe->env->env_dll)) ||
      !(tmp2 = search_for_env_variable("PWD", exe->env->env_dll)))
    return (-1);
  if ((chdir(tmp->value)) == -1)
    {
      printf("%s\n", strerror(errno));
      return (-1);
    }
  if (!(pwd = get_env_line("PWD", tmp->value))
      || !(oldpwd = get_env_line("OLDPWD", tmp2->value)))
    return (-1);
  env_setting_spec(exe, pwd, oldpwd, tmp2);
  return (0);
}

int		cd_progressive(t_execution *exe, t_cmd *cmd)
{
  char		*pwd;
  t_env_dll	*tmp;
  char		*swap;

  if (!(tmp = search_for_env_variable("PWD", exe->env->env_dll)))
    return (-1);
  if ((chdir(cmd->stock[1])) == -1)
    {
      printf("%s\n", strerror(errno));
      return (-1);
    }
  if (!(swap = supercat(tmp->value, "/", cmd->stock[1])))
    return (-1);
  if (!(pwd = get_env_line("PWD", swap))) // <<- SEGFAULT si supercat == NULL
    return (-1);
  cd_env_setting(exe, pwd, tmp);
  return (0);
}

int	cd_absolute(t_execution *exe, t_cmd *cmd)
{
  char		*pwd;
  t_env_dll	*tmp;

  if (!(tmp = search_for_env_variable("PWD", exe->env->env_dll)))
    return (-1);
  if ((chdir(cmd->stock[1])) == -1)
    {
      printf("%s\n", strerror(errno));
      return (-1);
    }
  if (!(pwd = get_env_line("PWD", cmd->stock[1])))
    return (-1);
  cd_env_setting(exe, pwd, tmp);
  return (0);
}

int	cd_regressive(t_execution *exe, t_cmd *cmd)
{
  char		*pwd;
  char		*swap;
  char		*oldpwd;
  t_env_dll	*tmp;
  int		errno;

  errno = 0;
  if (!(tmp = search_for_env_variable("PWD", exe->env->env_dll)))
    return (-1);
  if (!(oldpwd = get_env_line("OLDPWD", tmp->value)))
    return (-1);
  if (!(swap = cd_arbor_regress(tmp->value, cmd->stock[1])))
    return (-1);
  if (!(pwd = get_env_line("PWD", swap)))
    return (-1);
  if ((chdir(cmd->stock[1])) == -1)
    {
      printf("%s\n", strerror(errno));
      return (-1);
    }
  env_setting_spec(exe, pwd, oldpwd, tmp);
  return (0);
}

int	cd_other(t_execution *exe, t_cmd *cmd, char check)
{
  int	errno;
  int	retro;

  errno = 0;
  retro = retro_counter(cmd->stock[1]);
  if (strcmp(cmd->stock[1], "-") == 0)
    return (cd_oldpwd(exe, cmd));
  else if (strcmp(cmd->stock[1], "--") == 0)
    return (cd_doubleminus(exe, cmd));
  if ((access(cmd->stock[1], F_OK | R_OK)) == -1)
    {
      printf("%s\n", strerror(errno));
      return (-1);
    }
  if (retro == 0)
    {
      if (check == 1)
	return (cd_absolute(exe, cmd));
      return (cd_progressive(exe, cmd));
    }
  return(cd_regressive(exe, cmd));
}
