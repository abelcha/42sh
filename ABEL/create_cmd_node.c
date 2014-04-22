/*
** create_cmd_node.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon Apr 21 00:19:42 2014 chalie_a
** Last update Tue Apr 22 06:17:11 2014 chalie_a
*/

#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "parser.h"

static int		link_tree_nodes(t_cmd *elem, t_cmd *newelem)
{
  newelem->prev = elem->prev;
  newelem->next = elem;
  elem->prev->next = newelem;
  elem->prev = newelem;
  return (SUCCESS);
}

int			expected_after_pipe()
{
  fprintf(stderr, "Syntax Error : Expected expression after '|' token\n");
  return (FAILURE);
}

int			create_new_cmd_node(t_cmd *elem)
{
  t_cmd			*newelem;

  // printf("cmd->token = %d\n",elem->token); 
  //if ( elem->prev->size == 0)
  //  expected_after_pipe();
  if (!(newelem = calloc(1, sizeof(t_cmd))))
    return (FAILURE);
  newelem->stock = calloc(MEM_POOL, sizeof(char *));
  newelem->size = 0;
  return (link_tree_nodes(elem, newelem));
}
