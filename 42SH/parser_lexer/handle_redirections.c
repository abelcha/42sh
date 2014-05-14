/*
** handle_redirections.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon Apr 21 02:35:34 2014 chalie_a
** Last update Wed May 14 05:14:37 2014 chalie_a
*/

#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "parser.h"

extern const char		*token_tab[T_NBR + 1];

int		error_handling(int tk1, int tk2)
{
  if (tk2 == T_EOL)
    return(error_handling(tk1, tk2 + 1));
  fprintf(stderr, "Syntax Error : unexpected token ");
  fprintf(stderr, "'%s' after '%s' redirection token\n",
    token_tab[tk2], token_tab[tk1]);
  return(FAILURE);
}

int		delete_filename_token(t_token *token, int flag)
{
  token->prev->next = token->next;
  token->next->prev = token->prev;
  if (flag)
    free(token);
  else
    token->data = NULL;
  token = NULL;
  return (SUCCESS);
}

t_red		*init_red()
{
  t_red		*root;

  if (!(root = calloc(1, sizeof(t_red))))
    return (NULL);
  root->prev = root;
  root->next = root;
  return (root);
}

int			add_elem(t_red *elem)
{
  t_red		*newelem;

  if (!(newelem = calloc(1, sizeof(t_red))))
    return (FAILURE);
  newelem->prev = elem->prev;
  newelem->next = elem;
  elem->prev->next = newelem;
  elem->prev = newelem;
  return (SUCCESS);
}


int		redirections(t_cmd *cmd, t_token *token)
{
  if (token->next->token != T_CMD)
    return (error_handling(token->token, token->next->token));
  if (!cmd->red)
    if (!(cmd->red = init_red()))
      return (FAILURE);
  if (add_elem(cmd->red) == FAILURE)
    return (FAILURE);
  token->next->data[token->next->data_size] = 0;
  cmd->red->prev->name = token->next->data;
  cmd->red->prev->token = token->token;
  delete_filename_token(token->next, 1);
  delete_filename_token(token, 0);
  return (SUCCESS);
}
