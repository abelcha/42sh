/*
** lexer.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Apr 20 09:52:11 2014 chalie_a
** Last update Mon May 19 13:00:40 2014 chalie_a
*/

#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "parser.h"
#include "sh.h"

#define BEG_SEM	(token->prev->token == T_EOL && token->token == T_SEM)

static t_parse_tree	*init_tree()
{
  t_parse_tree		*root;

  if (!(root = calloc(1, sizeof(t_parse_tree))))
    return (NULL);
  root->prev = root;
  root->next = root;
  return (root);
}

int			lexical_error(t_token *token)
{
  if (token->prev->token != T_CMD && (IS_MAJOR(token->token)) && !BEG_SEM)
    return (lex_error(token->prev->token, BEFORE, token->token));
  if (token->token == T_PIPE && token->prev->token != T_CMD)
    return (lex_error(token->token, AFTER, token->prev->token));
  return (SUCCESS);
}

static int		add_token_or_create_node(t_parse_tree *root,
						 t_token *token, t_shell *sh)
{
  if (lexical_error(token) == FAILURE)
    return (FAILURE);
  if (IS_MAJOR(token->token))
    return (create_new_tree_node(root, token));
  else
    return (add_token_in_node(root->prev, token, sh));
}

static int		fill_tree(t_parse_tree *root, t_token *beg, t_shell *sh)
{
  t_token		*token;
  t_token		*save;

  token = beg->next;
  if (create_new_tree_node(root, token) == FAILURE)
    return (FAILURE);
  while (token != beg && (save = token->next->next))
    {
      if (add_token_or_create_node(root, token, sh) == FAILURE)
	return (FAILURE);
      else if (token && token->data)
	token = token->next;
      else if (token->token == T_AMP && x_free(token))
	token = save->prev;
      else if(x_free(token))
	token = save;
    }
  if (LLG(token->prev->token))
    return (lex_error(token->prev->token, BEFORE, token->token));
  return (SUCCESS);
}

t_parse_tree		*start_parsing(t_token *token, t_shell *sh)
{
  t_parse_tree		*root;

  if (!token || !(root = init_tree()))
    return (NULL);
  if (fill_tree(root, token, sh) == FAILURE)
    return (free_tree(root));
  return (root);
}
