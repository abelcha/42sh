/*
** lexer.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Apr 20 09:52:11 2014 chalie_a
** Last update Mon Apr 21 02:26:05 2014 chalie_a
*/

#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "parser.h"

static t_parse_tree	*init_tree()
{
  t_parse_tree		*root;

  if (!(root = calloc(1, sizeof(t_parse_tree))))
    return (NULL);
  root->prev = root;
  root->next = root;
  return (root);
}

static int			add_token_or_create_node(t_parse_tree *root,
							 t_token *token)
{
  if (IS_MAJOR(token->token))
    return (create_new_tree_node(root, token));
  else
    return (add_token_in_node(root->prev, token));
}

int			fill_tree(t_parse_tree *root, t_token *beg)
{
  t_token		*token;

  token = beg;
  if (create_new_tree_node(root, token) == FAILURE)
    return (FAILURE);
  while ((token = token->next) != beg)
    if (add_token_or_create_node(root, token) == FAILURE)
      return (FAILURE);
  return (SUCCESS);
}

int		start_parsing(t_token *token)
{
  t_parse_tree	*root;

  if (!(root = init_tree()))
    return (FAILURE);
  if (fill_tree(root, token) == FAILURE)
    return (FAILURE);
  display_tree(root);
  free_tree(root);
  return (SUCCESS);
}

