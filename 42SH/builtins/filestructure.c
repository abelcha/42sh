/*
** filestructure.c for 42sh in /home/coutar_a/rendu/42sh/42SH/builtins
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Sat May 17 17:10:24 2014 coutar_a
** Last update Mon May 19 21:43:03 2014 coutar_a
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sh.h"

char	*cd_arbor_regress(char *str, char *command)
{
  int	stop;
  int	check;
  char	*tmp;

  check = retro_counter(command);
  stop = strlen(str);
  while (stop != 0 && check != 0)
    {
      if (str[stop] == '/')
	check--;
      stop--;
    }
  stop++;
  if (stop <= 0)
    return (str);
  str[stop] = '\0';
  return (str);
}

char	*allocstrcat(char *dest, char *src)
{
  char	*ret;
  int	l;
  int	i;
  int	j;

  i = 0;
  j = 0;
  l = strlen(dest) + strlen(src) + 1;
  if ((ret = malloc((l) * sizeof(char))) == NULL)
    return (NULL);
  ret[l - 1] = '\0';
  while (dest[i] != '\0')
    {
      ret[i] = dest[i];
      i++;
    }
  while (src[j] != '\0')
    {
      ret[i] = src[j];
      i++;
      j++;
    }
  return (ret);
}

char	*supercat(char *str1, char *str2, char *str3)
{
  char	*swap;
  char	*swap2;

  if (!(swap = allocstrcat(str1, str2)))
    return (NULL);// <- malloc inutile
  if (!(swap2 = allocstrcat(swap, str3)))
    return (NULL);
  free(swap);
  return (swap2);
}

int	cd_env_setting(t_execution *exe, char *pwd, t_env_dll *tmp)
{
  t_env_dll	*tmp2;
  char		*oldpwd;

  if (!(oldpwd = get_env_line("OLDPWD", tmp->value)))
    return (-1);
  free(tmp->name);
  fill_env_struct(tmp, pwd);
  if(!(tmp2 = search_for_env_variable("OLDPWD", exe->env->env_dll)))
    add_env_variable(exe->env->env_dll, oldpwd);
  else
    {
      free(tmp2->name);
      fill_env_struct(tmp2, oldpwd);
    }
  put_env_in_tab(exe->env);
  return (0);
}

int	env_setting_spec(t_execution *exe, char *pwd,
			     char *oldpwd, t_env_dll *tmp)
{
  t_env_dll	*tmp2;

  free(tmp->name);
  fill_env_struct(tmp, pwd);		//<<- SEGFAULT si pwd == NULL
  if(!(tmp2 = search_for_env_variable("OLDPWD", exe->env->env_dll)))
    add_env_variable(exe->env->env_dll, oldpwd);
  else
    {
      free(tmp2->name);
      fill_env_struct(tmp2, oldpwd);
    }
  put_env_in_tab(exe->env);
  return (0);
}
