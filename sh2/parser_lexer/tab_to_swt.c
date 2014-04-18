/*
** tab_to_swt.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/parser_lexer
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:44:46 2014 chalie_a
** Last update Sun Mar  9 22:44:46 2014 chalie_a
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mysh.h"

static void	*exec_failure(char ***stock, char **tab)
{
  my_putstr("Error : Command not found.\n");
  triple_free(stock);
  double_free(tab);
  return (NULL);
}

static	int	to_buildins(char **stock, char **env, int status)
{
  destination(stock, env, status);
  double_free(stock);
  return (SUCCESS);
}

static void	*parsing_failed(char ***stock, char **tab)
{
  triple_free(stock);
  double_free(tab);
  return (NULL);
}

char	***tab_to_swt(char **tab, int len, char **env, char **paths)
{
  char	***stock;
  int	i = 0;
  int	status;
  int	x;

  x = -1;
  if (!(stock = x_calloc(len, sizeof(char **))))
    return (NULL);
  while (tab[++x])
    {
      stock[i] = to_tab(tab[x], 0, ' ');
      if (!stock[i])
	parsing_failed(stock, tab);
      else if ((status = compare(stock[i][0])) != NONE)
	to_buildins(stock[i], env, status);
      else if (is_command(paths, stock[i][0]) == FALSE)
	return (exec_failure(stock, tab));
      else if ((stock[i] = globbing_parser(stock[i])))
	++i;
    }
  double_free(tab);
  stock[i] = NULL;
  return (stock);
}
