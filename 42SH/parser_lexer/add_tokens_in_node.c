/*
** add_token_in_node.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Apr 20 09:52:11 2014 chalie_a
** Last update Mon May 19 17:26:17 2014 chalie_a
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include "tokenizer.h"
#include "parser.h"
#include "sh.h"


static int			replace_alias(char **tmp, t_cmd *cmd)
{
  int				i;

  i = -1;
  while (tmp[++i])
    {
      printf("add%d  %s\n", cmd->size, tmp[i]);
      cmd->stock[cmd->size] = tmp[i];
      cmd->size++;
    }
  cmd->size--;
  return (SUCCESS);
}

static int			fill_data_stock(t_cmd *cmd, t_shell *sh, t_token *token)
{
  char				**tmp;

  token->data[token->data_size] = 0;
  //  if (!(tmp = is_an_alias(token->data, sh)))
  cmd->stock[cmd->size] = token->data;
  //  else
  // replace_alias(tmp, cmd);
  cmd->stock[++(cmd->size)] = NULL;
  return (SUCCESS);
}

static int			add_data_in_cmd(t_cmd *cmd,
						t_token *token,
						t_shell *sh)
{
  if (!cmd)
    return (FAILURE);
  if (!cmd->stock || cmd->size >= cmd->realloc_cpt)
    if (!(cmd->stock = realloc(cmd->stock, ++(cmd->realloc_cpt) * MEM_POOL)))
      return (FAILURE);
  return (fill_data_stock(cmd, sh, token));
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
    result = add_data_in_cmd(tmp->cmd->prev, token, sh);
  else
    result = SUCCESS;
  return (result);
}
