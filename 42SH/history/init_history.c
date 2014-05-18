/*
** init_history.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/history
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon May 12 22:21:05 2014 chalie_a
** Last update Sun May 18 17:40:33 2014 chalie_a
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

  if (!(line->history = init_root_history()))
    return (FAILURE);
  if ((fd = open("./.42sh_history", (O_RDWR | O_CREAT | O_APPEND), 0777)) < 0)
    return (FAILURE);
  while ((str = gnl(fd)))
    if (add_elem_in_history(line->history) == FAILURE)
      return (FAILURE);
    else
      {
	line->history->prev->data = str;
	if ((line->history->prev->len = strlen(str)) > BUFF_LINE);
	//	  return (FAILURE);
      }
  close(fd);
  return (SUCCESS);
}

int		add_in_history_dll(t_line *line)
{
  if (my_strcmp(line->line, line->history->prev->data))
    if (add_elem_in_history(line->history) != FAILURE)
      {
	line->history->prev->len = line->line_len;
	if (!(line->history->prev->data = strdup(line->line)))
	  return (FAILURE);
      }
  return (SUCCESS);
}
