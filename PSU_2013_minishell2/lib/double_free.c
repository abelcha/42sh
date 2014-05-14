/*
** double_free.c for shel in /home/chalie_a/rendu/PSU_2013_minishell1/sources
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sat Dec 28 05:45:10 2013 chalie_a
** Last update Sun Mar  9 16:38:52 2014 chalie_a
*/

#include <stdlib.h>

void	double_free(char **stock)
{
  int	i;

  i = 0;
  while (stock[i])
    {
      if (stock[i] != NULL)
	{
	  free(stock[i]);
	  stock[i] = NULL;
	}
      i++;
    }
  if (stock != NULL)
    {
      free(stock);
      stock = NULL;
    }
}

void	triple_free(char ***stock)
{
  int	i;
  int	j;

  i = -1;
  while (stock[++i])
    {
      j = -1;
      while (stock[i][++j])
	{
	  free(stock[i][j]);
	  stock[i][j] = NULL;
	}
      free(stock[i]);
    }
  free(stock);
}

void	quad_free(char ****stock)
{
  int	i;

  i = -1;
  while (stock[++i])
    triple_free(stock[i]);
  free(stock);
}

void	free_all(char **path, char **stock)
{
  if (path != NULL)
    double_free(path);
  if (stock != NULL)
    double_free(stock);
}
