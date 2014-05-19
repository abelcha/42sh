/*
** init_history.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/history
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon May 12 22:21:05 2014 chalie_a
** Last update Mon May 19 12:32:43 2014 chalie_a
*/

#include <fcntl.h>
#include <stdlib.h>
#include "edit.h"
#include "sh.h"

int			add_elem_in_history(t_history *elem)
{
  t_history		*newelem;

  if (!(newelem = calloc(1, sizeof(t_history))))
    return (FAILURE);
  newelem->prev = elem->prev;
  newelem->next = elem;
  elem->prev->next = newelem;
  elem->prev = newelem;
  return (SUCCESS);
}

t_history		*init_root_history()
{
  t_history		*root;

  if (!(root = calloc(1, sizeof(t_history))))
    return (NULL);
  root->prev = root;
  root->next = root;
  return (root);
}

int		init_history(t_line *line)
{
  int		fd;
  char		*str;
  int		i;

  i = -1;
  if (!(line->sh->history = init_root_history()))
    return (FAILURE);
  if ((fd = open("./.42sh_history", (O_RDWR | O_CREAT | O_APPEND), 0777)) < 0)
    return (FAILURE);
  while ((str = gnl(fd)) && ++i < 1000)
    if (add_elem_in_history(line->sh->history) == FAILURE)
      return (FAILURE);
    else
      {
	line->sh->history->prev->data = str;
	line->sh->history->prev->len = strlen(str);
      }
  close(fd);
  return (SUCCESS);
}

int		add_in_history_dll(t_line *line)
{
  if (my_strcmp(line->line, line->sh->history->prev->data))
    if (add_elem_in_history(line->sh->history) != FAILURE)
      {
	line->sh->history->prev->len = line->line_len;
	if (!(line->sh->history->prev->data = strdup(line->line)))
	  return (FAILURE);
      }
  return (SUCCESS);
}
