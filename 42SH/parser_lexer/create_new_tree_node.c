/*
** lexer.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel.chalier@epitech.eu>
** 
** Started on  Sun Apr 20 09:52:11 2014 chalie_a
** Last update Sat May 24 18:31:39 2014 chalie_a
*/

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "tokenizer.h"

static t_cmd		*init_cmd()
{
  t_cmd			*root;

  if (!(root = calloc(1, sizeof(t_cmd))))
    return (NULL);
  root->prev = root;
  root->next = root;
  return (root);
}

static void		link_nodes(t_parse_tree *root, t_parse_tree *new)
{
  new->prev = root->prev;
  new->next = root;
  root->prev->next = new;
  root->prev = new;
}

int			create_new_tree_node(t_parse_tree *root, t_token *token)
{
  t_parse_tree		*new;

  if (!(new = calloc(1, sizeof(t_parse_tree))))
    return (FAILURE);
  if (!(new->cmd = init_cmd()))
    return (FAILURE);
  if (create_new_cmd_node(new->cmd) == FAILURE)
    return (FAILURE);
  link_nodes(root, new);
  new->token = token->token;
  return (SUCCESS);
}
