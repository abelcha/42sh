/*
** tokeniser.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Thu Apr 17 23:43:50 2014 chalie_a
** Last update Fri Apr 18 06:28:40 2014 chalie_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

static const char		*token_tab[10] = {"<<", "<",
						 ">>", ">",
						 "||", "|",
						 "&&", ";", "DATA", "END_OF_LINE"};

void			print_data(t_token *root)
{
  t_token *tmp;

  tmp = root;
  while ((tmp = tmp->next) != root)
    {
      int	i = -1;
      printf("token = %s\n \"", token_tab[tmp->token]);
      while (++i < tmp->data_size)
	printf("%c", tmp->data[i]);
      printf("\"\n");
    }
  printf("END_OF_LINE\n");
}

int			is_separator(char c)
{
  static const char	cmp[2] = {SPACE, TAB};
  int			i;
  
  i = -1;
  while (++i < 3)
    if (cmp[i] == c)
      return (TRUE);
  return (FALSE);
}

int			add_elem(t_token *elem, t_token	*newelem)
{
  newelem->prev = elem->prev;
  newelem->next = elem;
  elem->prev->next = newelem;
  elem->prev = newelem;
  return (SUCCESS);
}

int			get_data_len(char *str)
{
  int			i;
  int			j;
  static const char	*token_char = T_CHAR;

  i = -1;
  j = -1;
  while (str[++i] && !(j = 0))
    while (++j < T_CHAR_NBR)
      if (str[i] == token_char[j] || !str[i])
	return (i);
  return (i);
    
}

int			find_token(t_token *token, char *cmp)
{
  while (++(token->token) != 8)
    if (TOKEN_MATCH(token_tab[token->token], cmp) == TRUE)
      return (token->token % 2 == 0 ? 2 : 1);
  return (get_data_len(cmp));
}

int			add_token_in_list(t_token *root, int i)
{
  t_token		*new_elem;

  if (!(new_elem = malloc(sizeof(t_token))))
    return (FAILURE);
  add_elem(root, new_elem);
  new_elem->token = -1;
  new_elem->data = &(root->data)[i];
  new_elem->data_size = find_token(new_elem, &(root->data)[i]);
  return (i + new_elem->data_size - 1);
}

int			tokenizer_parsing(t_token *root, int i)
{
  if (root->data[i] == '\0')
    return (SUCCESS);
  if (IS_SEP(root->data[i]) == FALSE)
    if ((i = add_token_in_list(root, i)) == FAILURE)
      return (FAILURE);
  return (tokenizer_parsing(root, ++i));
}

t_token			*init_root()
{
  t_token		*root;

  if (!(root = malloc(sizeof(t_token))))
    return (NULL);
  root->token = T_EOL;
  root->prev = root;
  root->next = root;
  return (root);
}


t_token			*tokenizer(char *str)
{
  t_token		*root;

  root = init_root();
  if (!root)
    return (NULL);
  root->data = str;
  tokenizer_parsing(root, 0);
  return (root);
}

int		main(int ac, char **av)
{
  t_token		*root;

  char	*str = strdup(av[1]);

  root = tokenizer(str);
  print_data(root);
}
