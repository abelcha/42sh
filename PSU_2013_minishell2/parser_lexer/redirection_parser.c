/*
** redirection_parser.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/parser_lexer
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:44:18 2014 chalie_a
** Last update Sun Mar  9 22:44:18 2014 chalie_a
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mysh.h"
#include "parser_lexer.h"

static t_dll		*red_type(char c, char c2, t_dll *list, int *j)
{
  if (c == '<')
    {
      type = INP;
      if (c2 == '<' && ++(*j))
	list->in_red = __DOUBLE_RED;
      else
	list->in_red = __SIMPLE_RED;
    }
  else
    {
      type = OUTP;
      if (c2 == '>' && ++(*j))
	list->out_red = DOUBLE_RED__;
      else
	list->out_red = SIMPLE_RED__;
    }
  return (list);
}

static char		*same_line(char *curr, int j)
{
  int			i;
  char			*filename;

  i = j;
  while (curr[++i] && curr[i] != '|' && curr[i] != ';');
  filename = my_strdup(&curr[j]);
  if (j > 1 &&  (curr[j - 2] == '>' || curr[j - 2] == '<'))
    curr[j - 2] = 3;
  filename[i - j--] = '\0';
  while (j < i && (curr[j++] = 3));
  return (filename);
}

static char		*nxt_line(char *curr, char *next, int j)
{
  int			i;
  char			*filename;

  i = 0;
  if (j > 3 && (curr[j - 2] == '>' || curr[j - 2] == '<'))
    curr[j - 2] = '\0';
  else
    curr[j - 1] = '\0';
  i = j;
  if (i < my_strlen(next))
    while (i >= 0 && next[++i] && next[i] != '|' && next[i] != ';');
  filename = my_strdup(next);
  if (i < my_strlen(filename))
    filename[i] = '\0';
  i = -1;
  while (next[++i] && next[i] != '|' && next[i] != ';')
    next[i] = 3;
  return (filename);
}

static char		*find_filename(char *curr, char *next, int j)
{
  char			*filename;

  if (curr[j] == '\0' || curr[j] == '|' || curr[j] == ';')
    {
      if (next == NULL)
	return (NULL);
      else
	filename = nxt_line(curr, next, j);
    }
  else
    filename = same_line(curr, j);
  return (filename);
}

t_dll		*handle_red(char **stock, t_dll *list)
{
  int		i;
  int		j;

  i = -1;
  list->file_name[INP] = NULL;
  list->file_name[OUTP] = NULL;
  while (stock[++i])
    {
      j = -1;
      while (stock[i][++j])
	if (stock[i][j] == '<' || stock[i][j] == '>')
	  {
	    red_type(stock[i][j], stock[i][j + 1], list, &j);
	    x_free(list->file_name[type]);
	    list->file_name[type] = find_filename
	      (stock[i], stock[i + 1], j + 1);
	    if (type == OUTP)
	      x_open(list->file_name[OUTP]);
	  }
    }
  return (list);
}
