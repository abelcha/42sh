/*
** parsing.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/parser_lexer
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:44:08 2014 chalie_a
** Last update Sun Mar  9 22:44:08 2014 chalie_a
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mysh.h"
#include "parser_lexer.h"

static char		*wt_len(char **stock)
{
  int			i;
  int			j;
  int			x;
  char			*cpy;

  x = -1;
  i = -1;
  while (stock[++i] && (j = -1))
    while (stock[i][++j]);
  cpy = x_calloc((j * i * BUFF_SIZE), sizeof(char));
  i = -1;
  if (cpy)
  while (stock[++i])
      {
	j = -1;
	while (stock[i][++j])
	  if (stock[i] && stock && stock[i][j] && stock[i][j] != 3
	      && stock[i][j] != '>' && stock[i][j] != '<')
	  cpy[++x] = stock[i][j];
	cpy[++x] = ' ';
	x_free(stock[i]);
    }
  x_free(stock);
  return (cpy);
}

t_dll			*command_parsing(char *str, char **env, char **paths)
{
  t_dll			*list;
  char			**stock;

  if (!str)
    return (NULL);
  stock = to_tab(str, 0, ' ');
  x_free(str);
  if (!(list = malloc(sizeof(t_dll))))
    return (NULL);
  list->out_red = -1;
  list->in_red = -1;
  list->err_red = -1;
  handle_red(stock, list);
  list->command = cw_tab(wt_len(stock), env, paths);
  if (list->command == NULL)
    {
      x_free(list->file_name[INP]);
      x_free(list->file_name[OUTP]);
      free(list);
      list = NULL;
    }
 return (list);
}
