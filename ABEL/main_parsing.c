/*
** lexer.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Apr 20 09:52:11 2014 chalie_a
** Last update Tue May  6 12:30:04 2014 chalie_a
*/

#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "parser.h"
#include "sh.h"

static t_parse_tree	*init_tree()
{
  t_parse_tree		*root;

  if (!(root = calloc(1, sizeof(t_parse_tree))))
    return (NULL);
  root->prev = root;
  root->next = root;
  return (root);
}

int			lexical_error(t_parse_tree *root, t_token *token)
{
  if (token->prev->token != T_CMD  && (IS_MAJOR(token->token)))
    return (lex_error(token->prev->token, BEFORE, token->token));
  if (token->token == T_PIPE && token->prev->token != T_CMD)
    return (lex_error(token->token, AFTER, token->prev->token));
  return (SUCCESS);
}

static int		add_token_or_create_node(t_parse_tree *root,
							 t_token *token)
{
  if (lexical_error(root, token) == FAILURE)
    return (FAILURE);
  if (IS_MAJOR(token->token))
    return (create_new_tree_node(root, token));
  else
    return (add_token_in_node(root->prev, token));
}

static int		fill_tree(t_parse_tree *root, t_token *beg)
{
  t_token		*token;

  token = beg;
  if (create_new_tree_node(root, token) == FAILURE)
    return (FAILURE);
  while ((token = token->next) != beg)
    if (add_token_or_create_node(root, token) == FAILURE)
      return (FAILURE);
  if (LLG(token->prev->token))
    {
      return (lex_error(token->prev->token, BEFORE, token->token));
      printf("NIKTAMERERERER\n");
      return (FAILURE);
    }
  return (SUCCESS);
}

t_parse_tree		*start_parsing(t_token *token)
{
  t_parse_tree		*root;

  if (!(root = init_tree()))
    return (NULL);
  if (fill_tree(root, token) == FAILURE)
    return (free_tree(root));
  display_tree(root);
  exec_cmd(root);
  return (root);
}

