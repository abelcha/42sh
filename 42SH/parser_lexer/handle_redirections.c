/*
** handle_redirections.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon Apr 21 02:35:34 2014 chalie_a
** Last update Wed May 14 21:54:44 2014 chalie_a
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

int			find_red_token(int token)
{
  static const int	tr_tab[6] = {T_RED_CC, T_RED_C, T_RED_D,
				     T_RED_DD, T_AMP_R, T_R_AMP};
  int			i;

  i = -1;
  while (++i < 6)
    if (token == tr_tab[i])
      return (i);
  return (0);
}

int		redirections(t_cmd *cmd, t_token *token)
{
  int		red_token;

  if (token->next->token != T_CMD)
    return (error_handling(token->token, token->next->token));
  red_token = find_red_token(token->token);
  printf("newtoken = %d\n", red_token);
  if (!cmd->red[red_token / 2])
    if (!(cmd->red[red_token / 2] = calloc(1, sizeof(t_red))))
      return (FAILURE);
  cmd->red[red_token / 2]->token = red_token;
  //cmd->red[red_token / 2]->name = token->next->data;
  token->next->data[token->next->data_size] = 0;
  //cmd->red->prev->name = token->next->data;
  //cmd->red->prev->token = token->token;
  delete_filename_token(token->next, 1);
  delete_filename_token(token, 0);
  return (SUCCESS);
}
