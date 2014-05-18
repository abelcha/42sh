/*
** add_token_in_node.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Apr 20 09:52:11 2014 chalie_a
** Last update Sat May 17 19:11:10 2014 chalie_a
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include "tokenizer.h"
#include "parser.h"
#include "sh.h"

static int			add_data_in_cmd(t_cmd *cmd,
						const t_token *token)
{
  if (!cmd)
    return (0);
  if (!cmd->stock)
    return (FAILURE);
  cmd->stock[cmd->size] = token->data;
  cmd->stock[cmd->size][token->data_size] = 0;
  ++(cmd->size);
  return (SUCCESS);
}

static int			is_redir(const int t)
{
  if (t == 0 || t == 2 || (t >= 8 && t <= 11))
    return (1);
  return (0);
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
						  t_execution *exe)
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
    result = redirections(tmp->cmd->prev, token, exe);
  else if (token->token == T_CMD)
    result = add_data_in_cmd(tmp->cmd->prev, token);
  else
    result = SUCCESS;
  return (result);
}
