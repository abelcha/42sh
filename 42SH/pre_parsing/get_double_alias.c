/*
** alias.c for Project-Master in /home/tovazm/rendu/42sh/42SH
** 
** Made by chalie_a
** Login   <abel.chalier@epitech.eu>
** 
** Started on  Mon May 19 12:46:55 2014 chalie_a
** Last update Sat May 24 18:24:46 2014 chalie_a
*/

#include <stdio.h>
#include <stdlib.h>
#include "sh.h"
#include "parser.h"

static int		tab_len(char **s1)
{
  int			i;

  i = -1;
  if (!(s1))
    return (0);
  while (s1[++i]);
  return (i);
}

static void		insert_alias(t_alias *t1, int pos,
				     t_alias *t2)
{
  char			**stock;
  char			*save;
  int			i;
  int			k;

  i = -1;
  if (!(stock = calloc(tab_len(t1->cmd) + tab_len(t2->cmd) + 2, 8)))
    return ;
  while (++i < pos)
    stock[i] = t1->cmd[i];
  save = t1->cmd[i];
  k = i + 1;
  while (t2->cmd[pos])
    if (!(stock[i++] = my_strdup(t2->cmd[pos++])))
      return ;
  while (t1->cmd[k])
    stock[i++] = t1->cmd[k++];
  XFREE(save);
  XFREE(t1->cmd);
  t1->cmd = stock;
}

static void		similar_part(t_alias *tmp, t_alias *root)
{
  t_alias		*tmp2;
  int			i;

  tmp2 = root;
  while ((tmp2 = tmp2->next) != root)
    {
      i = 1;
      while (tmp->cmd[++i])
	if ((!my_strcmp(tmp->cmd[i], tmp2->cmd[1]) && tmp != tmp2))
	  {
	    insert_alias(tmp, i, tmp2);
	    break ;
	  }
   }
}

void			check_double_alias(t_alias *alias)
{
  t_alias		*tmp;

  tmp = alias;
  while ((tmp = tmp->next) != alias)
    similar_part(tmp, alias);
}
