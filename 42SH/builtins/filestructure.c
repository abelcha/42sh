/*
** filestructure.c for 42sh in /home/coutar_a/rendu/42sh/42SH/builtins
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Sat May 17 17:10:24 2014 coutar_a
** Last update Sun May 18 14:54:48 2014 coutar_a
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sh.h"

char	*cd_arbor_regress(char *str)
{
  int	stop;

  stop = strlen(str);
  while (str[stop] != '/')		// <<- SEGFAULT si PWD=toto
    stop--;
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

  swap = allocstrcat(str1, str2);	// <- malloc inutile
  swap2 = allocstrcat(swap, str3);
  free(swap);
  return (swap2);
}

int	cd_chdir_error(void)
{
  printf("Error, file is not a directory.\n");
  return (-1);
}

int	cd_env_setting(t_execution *exe, char *pwd, t_env_dll *tmp)
{
  t_env_dll	*tmp2;
  char		*oldpwd;

  oldpwd = get_env_line("OLDPWD", tmp->value);
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
