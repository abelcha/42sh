/*
** check_out.c for sh7 in /home/chalie_a/rendu/PSU_2013_minishell2/buildins
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:39:31 2014 chalie_a
** Last update Sun Mar  9 22:39:31 2014 chalie_a
*/

#include <stdlib.h>
#include "mysh.h"
#include "env.h"

void		prompt(char **env, int i)
{
  my_putstr("\033[39;31m");
  my_putstr(get_env(env, "LOGNAME="));
  my_putchar('@');
  my_putstr(get_env(env, "USERNAME="));
  my_put_nbr(i);
  my_putstr(")>\033[0m");
  i++;
}

int		pwd_to_old(char **env, int new)
{
  int		old;
  char		*str;
  char		*one;

  one = my_strdup("OLD");
  old = change_in_tab(env, "OLDPWD=");
  str = my_strcat(one, env[new]);
  x_free(one);
  if (old == NONE)
    {
      add_in_tab(env, str);
      x_free(str);
    }
  else
    {
      x_free(env[old]);
      env[old] = str;
    }
  return (SUCCESS);
}
