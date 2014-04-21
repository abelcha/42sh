/*
** free_parse_tree.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Apr 20 23:42:24 2014 chalie_a
** Last update Mon Apr 21 00:32:25 2014 chalie_a
*/

#include <stdlib.h>
#include "parser.h"

static int			x_free(void *ptr)
{
  if (ptr)
    {
      free(ptr);
      ptr = NULL;
    }
  return (42);
}

static void			free_cmd(t_cmd *root)
{
  t_cmd				*tmp;
  t_cmd				*save;

  save = root->prev;
  tmp = root;
  while ((tmp = tmp->next) != root)
    {
      x_free(tmp->prev->stock);
      free(tmp->prev);
    }
  x_free(save->stock);
  x_free(save);
}

void				free_tree(t_parse_tree *root)
{
  t_parse_tree			*tmp;
  t_parse_tree			*save;

  save = root->prev;
  tmp = root;
  while ((tmp = tmp->next) != root)
    {
      if (tmp->prev->cmd)
	free_cmd(tmp->prev->cmd); 
      x_free(tmp->prev);
    }
  free_cmd(save->cmd);
  x_free(save);
}

