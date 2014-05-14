/*
** print_env.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/buildins
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:40:16 2014 chalie_a
** Last update Sun Mar  9 22:40:16 2014 chalie_a
*/

#include "mysh.h"
#include "env.h"

int		dollar_sign(char **stock, char **env)
{
  char		*str;

  str = my_strcat(&stock[0][1], "=");
  if (!str)
    {
      force_exit = TRUE;
      return (FAILURE);
    }
  if (my_strcmp(str, (get_env(env, str))))
    {
      my_putstr(get_env(env, str));
      my_putchar('\n');
    }
  else
    {
      my_putstr("error : `");
      my_putstr(&stock[0][1]);
      my_putstr("`, no such env. variable.\n");
    }
  x_free(str);
  return (SUCCESS);
}

int		print_dir(char **stock, char **env)
{
  cast(stock);
  my_putstr(get_env(env, "PWD="));
  my_putchar('\n');
  return (SUCCESS);
}
