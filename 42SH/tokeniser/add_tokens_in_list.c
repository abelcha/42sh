/*
** tokeniser.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Thu Apr 17 23:43:50 2014 chalie_a
** Last update Fri May 16 10:04:39 2014 chalie_a
*/

#include <stdlib.h>
#include "tokenizer.h"

extern const char	*token_tab[T_NBR + 1];

static int		get_data_len(const char *str)
{
  static const char	*token_char = T_CHAR;
  int			i;
  int			j;

  i = -1;
  j = -1;
  while (str[++i] && (j = -1))
    while (++j < T_CHAR_NBR)
      if (str[i] == token_char[j] || !str[i] || str[i] == ' ' || str[i] == '\t')
	return (i);
  return (i);
}

static int		find_token(t_token *token, char *cmp)
{
  while (++(token->token) != T_CMD)
    if (TOKEN_MATCH(token_tab[token->token], cmp) == TRUE)
      return (token->token % 2 == 0 ? 2 : 1);
  return (get_data_len(cmp));
}

static int		link_token_node(t_token *elem, t_token *newelem)
{
  newelem->prev = elem->prev;
  newelem->next = elem;
  elem->prev->next = newelem;
  elem->prev = newelem;
  return (SUCCESS);
}

int			add_token_in_list(t_token *root, const int i)
{
  t_token		*new_elem;

  if (!(new_elem = calloc(1, sizeof(t_token))))
    return (FAILURE);
  link_token_node(root, new_elem);
  new_elem->token = -1;
  new_elem->data = &(root->data)[i];
  new_elem->data_size = find_token(new_elem, &(root->data)[i]);
  return (i + new_elem->data_size - 1);
}
