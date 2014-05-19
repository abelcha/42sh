/*
** alias.c for Project-Master in /home/tovazm/rendu/42sh/42SH
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon May 19 12:46:55 2014 chalie_a
** Last update Mon May 19 14:09:03 2014 chalie_a
*/

#include <stdlib.h>
#include "sh.h"
#include "parser.h"

char		**is_an_alias(char *str, t_shell *sh)
{
  t_alias	*tmp;

  tmp = sh->alias;
  while ((tmp = tmp->next) != sh->alias)
    {
      printf("%s == %s\n", tmp->name, str);
      if (!my_strcmp(tmp->name, str))
	return (&tmp->cmd[2]);
    }
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
