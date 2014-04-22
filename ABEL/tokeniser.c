/*
** main.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Thu Apr 17 23:43:50 2014 chalie_a
** Last update Tue Apr 22 06:07:42 2014 chalie_a
*/

#include <stdlib.h>
#include "sh.h"
#include "parser.h"
#include "tokenizer.h"

void			free_tokens(t_token *root)
{
  t_token		*tmp;
  t_token		*save;

  save = root->prev;
  tmp = root;
  while ((tmp = tmp->next) != root)
    free(tmp->prev);
  free(save);
}

int			main(int ac, char **av)
{
  t_token		*root;
  t_parse_tree		*tree;
  char			*str;
  int			i = 1;

  while ((str = gnl(0)))
    {
      root = get_tokens(str);
      if ((tree = start_parsing(root)))
	free_tree(tree);
      free(str);
      free_tokens(root);
      if (++i > 10000)
	return (0);
    }
}
