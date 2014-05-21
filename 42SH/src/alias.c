/*
** alias.c for Project-Master in /home/tovazm/rendu/42sh/42SH
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon May 19 12:46:55 2014 chalie_a
<<<<<<< HEAD
** Last update Wed May 21 11:16:21 2014 chalie_a
=======
** Last update Wed May 21 16:06:06 2014 kalatz_a
>>>>>>> 984c7eeeec8645e63a52154fd1a0db80b8fd19e9
*/

#include <stdio.h>
#include <stdlib.h>
#include "sh.h"
#include "parser.h"

char		**is_an_alias(char *str, t_shell *sh)
{
  t_alias	*tmp;

  tmp = sh->alias;
  while ((tmp = tmp->next) != sh->alias)
    if (!my_strcmp(tmp->name, str))
      return (&tmp->cmd[2]);
  return (NULL);
}

void		add_alias(t_shell *sh, char **stock)
{
  t_alias		*newelem;

  if (!stock || !stock[1]|| !stock[2])
    return ;
  if (!(newelem = calloc(1, sizeof(t_alias))))
    return ;
  newelem->name = stock[1];
  newelem->cmd = stock;
  newelem->prev = sh->alias->prev;
  newelem->next = sh->alias;
  sh->alias->prev->next = newelem;
  sh->alias->prev = newelem;
  return ;
}

int		tab_len(char **s1)
{
  int		i;

  i = -1;
  if (!(s1))
    return (0);
  while (s1[++i]);
  return (i);
}

void		insert_alias(t_alias *t1, int pos, t_alias *t2)
{
  char		**stock;
  int		i;
  int		k;

  i = 0;
  if (!(stock = calloc(tab_len(t1->cmd) + 
		       tab_len(t2->cmd) + 
		       2, sizeof(char *))))
    return ;
  while (i < pos)
    {
      stock[i] = t1->cmd[i];
      printf("1) stock[%d] = %s\n", i, stock[i]);
      ++i;
    } 
  k = i + 1;
  while (t2->cmd[pos])
    {
      if (!(stock[i] = my_strdup(t2->cmd[pos++])))
	return ;
      printf("2) stock[%d] = %s\n", i, stock[i]);
      ++i;
    }
  while (t1->cmd[k])
    {
      stock[i] = t1->cmd[k];
      printf("3) stock[%d] = %s\n", i, stock[i]);
      ++i;
      ++k;
    }
  free(t1->cmd);
  t1->cmd = stock;
}

t_alias		*similar_part(t_alias *tmp, t_alias *root)
{
  t_alias	*tmp2;
  int		i;

  tmp2 = root;
  while ((tmp2 = tmp2->next) != root)
    {
      i = 1;
      while (tmp->cmd[++i])
	if ((!my_strcmp(tmp->cmd[i], tmp2->cmd[1]) && tmp != tmp2))
	  {
	    printf("----->s1 = %s s2 = %s\n", tmp->cmd[i], tmp2->cmd[1]);
	    insert_alias(tmp, i, tmp2);
	    break ;
	  }
   }
}

void		check_double_alias(t_shell *sh, t_alias *alias)
{
  t_alias	*tmp;

  tmp = alias;
  while ((tmp = tmp->next) != alias)
    similar_part(tmp, alias);
}
