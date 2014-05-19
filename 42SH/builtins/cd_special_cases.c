/*
** cd_special_cases.c for 42sh in /home/coutar_a/rendu/42sh/42SH/builtins
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Mon May 19 19:37:41 2014 coutar_a
** Last update Mon May 19 20:38:04 2014 coutar_a
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "sh.h"

int		retro_counter(char *command)
{
  char		*retro;
  int		i;
  int		j;
  int		ret;

  ret = 0;
  i = 0;
  j = 0;
  retro = "..";
  while (command[i] != 0)
    {
      if (command[i] == retro[j] && command[i + 1] == retro[j + 1])
	ret++;
      i++;
    }
  return (ret);
}

int		cd_oldpwd(t_execution *exe, t_cmd *cmd)
{
  char		*oldpwd;
  char		*pwd;
  t_env_dll	*tmp;
  t_env_dll	*tmp2;

  (void)cmd;
  if (!(tmp = search_for_env_variable("OLDPWD", exe->env->env_dll)))
    {
      printf("Error : OLDPWD not set.\n");
      return (-1);
    }
  if (!(tmp2 = search_for_env_variable("PWD", exe->env->env_dll)))
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

int	cd_doubleminus(t_execution *exe, t_cmd *cmd)
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
  if (!(swap = cd_arbor_regress(tmp->value, "..")))
    return (-1);
  if (!(pwd = get_env_line("PWD", swap)))
    return (-1);
  if ((chdir("..")) == -1)
    {
      printf("%s\n", strerror(errno));
      return (-1);
    }
  env_setting_spec(exe, pwd, oldpwd, tmp);
  return (0);
}
