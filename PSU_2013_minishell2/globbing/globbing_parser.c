/*
** globbing_parser.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/globbing
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:41:23 2014 chalie_a
** Last update Sun Mar  9 22:41:23 2014 chalie_a
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_strings.h"
#include	"globbing.h"
#include	"mysh.h"

char			**realmove(char **stock, char **tmp, int i, int tmlen)
{
  int			stlen;
  char			**final;
  int			x;

  x = -1;
  stlen = -1;
  while (stock[++stlen])
    final = x_malloc((MEM_POOL + tmlen + stlen) * sizeof(char **));
  while (++x < i)
    final[x] = stock[x];
  free(stock[x]);
  while (tmp[x - i] && x < MEM_POOL)
    {
      final[x] = tmp[x - i];
      ++x;
    }
  while (stock[i] && x < MEM_POOL)
    {
      final[x] = stock[++i];
      ++x;
    }
  free(tmp);
  free(stock);
  final[x] = NULL;
  return (final);
}

static int		glob_type(char c)
{
  int			i;
  char			*cmp;

  cmp = GLOB;
  i = -1;
  while (cmp[++i])
    if (c == cmp[i])
      return (i);
  return (-1);
}

char			**globbing_parser(char **stock)
{
  int			i;
  int			j;
  int			type;

  i = 0;
  j = 0;
  while (stock[++i])
    {
      j = 0;
      while (stock[i][j])
	{
	  if ((type = glob_type(stock[i][j])) != -1 &&
	      (ESCP(stock[i], j) == FALSE))
	    {
	      if (type == 0)
		stock = wildcard_handler(stock, i);
	      break ;
	    }
	  ++j;
	}
    }
  return (stock);
}
