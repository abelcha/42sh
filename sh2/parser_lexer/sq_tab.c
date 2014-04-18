/*
** sq_tab.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/parser_lexer
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:44:33 2014 chalie_a
** Last update Sun Mar  9 22:44:33 2014 chalie_a
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mysh.h"

int	t_len(char *str, char c)
{
  int	i;
  int	j;

  j = 0;
  i = -1;
  while (str[++i])
    if (str[i] == c)
      j++;
  return (j + 2);
}

static void	*parsing_failure(char ****stock, char **tab)
{
  double_free(tab);
  quad_free(stock);
  return (NULL);
}

char		****cw_tab(char *str, char **env, char **paths)
{
  char		****stock;
  int		i;
  char		**tab;
  int		len;

  i = -1;
  if (!str)
    return (NULL);
  len =  t_len(str, '|');
  tab = to_tab(str, 0, ';');
  if (!tab || !(stock = x_calloc(t_len(str, ';') * 2, sizeof(char **))))
    return (NULL);
  x_free(str);
  while (tab[++i])
    {
      stock[i] = tab_to_swt(to_tab(tab[i], 0, '|'), len, env, paths);
      if (!stock[i])
	return (parsing_failure(stock, tab));
    }
  stock[i] = NULL;
  double_free(tab);
  return (stock);
}
