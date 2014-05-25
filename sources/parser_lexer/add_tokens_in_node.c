/*
** add_token_in_node.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel.chalier@epitech.eu>
** 
** Started on  Sun Apr 20 09:52:11 2014 chalie_a
** Last update Sat May 24 18:18:24 2014 chalie_a
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "parser.h"
#include "tokenizer.h"

static int			fill_data_stock(t_cmd *cmd, t_token *token)
{
  token->data[token->data_size] = 0;
  cmd->stock[cmd->size] = token->data;
  cmd->stock[++(cmd->size)] = NULL;
  return (SUCCESS);
}

static int			add_data_in_cmd(t_cmd *cmd,
						t_token *token)
{
  if (!cmd)
    return (FAILURE);
  if (cmd->size >= (cmd->realloc_cpt * _MEM_POOL))
    if (!(cmd->stock = realloc(cmd->stock, ++(cmd->realloc_cpt)
			       * _MEM_POOL * 8 + 8)))
      return (FAILURE);
  return (fill_data_stock(cmd, token));
}

static int			cmd_in_background(t_parse_tree *tmp,
						  t_token *token)
{
  if (tmp->cmd->prev->background == 1)
    return (lex_error(token->token, AFTER, token->prev->token));
  tmp->cmd->prev->background = 1;
  token->prev->next = token->next;
  token->next->prev = token->prev;
  token->data = NULL;
  return (SUCCESS);
}

int				add_token_in_node(t_parse_tree *tmp,
						  t_token *token,
						  t_shell *sh)
{
  int				result;

  if (token->token == T_AMP)
    return (cmd_in_background(tmp, token));
  if (token->token == T_PIPE)
    {
      result = LAST_PIPE ? expected_after_pipe() :
	create_new_cmd_node(tmp->cmd);
      ++(tmp->nb_pipes);
    }
  else if (IN_RED(token->token) || OUT_RED(token->token))
    result = redirections(tmp->cmd->prev, token, sh->exe);
  else if (token->token == T_CMD)
    result = add_data_in_cmd(tmp->cmd->prev, token);
  else
    result = SUCCESS;
  return (result);
}
