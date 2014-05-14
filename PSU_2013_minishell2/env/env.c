/*
** env.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/env
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:48:39 2014 chalie_a
** Last update Sun Mar  9 22:48:39 2014 chalie_a
*/

#include <stdlib.h>
#include "mysh.h"
#include "env.h"

int		print_env(char **stock, char **env)
{
  int		i;

  i = 1;
  if (!stock[1])
    while (env[i])
      {
	my_putstr(env[i]);
	my_putchar('\n');
	i++;
      }
  return (SUCCESS);
}

int		set_env(char **stock, char **env)
{
  int		j;

  j = 0;
  if (stock[1] == NULL)
    return (x_error(1));
  if (stock[2] != NULL)
    return (x_error(3));
  j = change_in_tab(env, stock[1]);
  if (j == -2)
    return (x_error(2));
  else if (j == -1)
    add_in_tab(env, stock[1]);
  else
    {
      free(env[j]);
      env[j] = my_strdup(stock[1]);
    }
  my_putstr(stock[1]);
  my_putchar('\n');
  return (SUCCESS);
}

int		unset_env(char **stock, char **env)
{
  if (stock[1] == NULL)
    return (unset_error(1, NULL));
  else if (stock[2] != NULL)
    return (unset_error(2, NULL));
  else if (del_in_tab(env, stock[1]) == NULL)
    return (unset_error(3, stock[1]));
  my_putstr(stock[1]);
  my_putstr(" is now unset.\n");
  return (SUCCESS);
}
