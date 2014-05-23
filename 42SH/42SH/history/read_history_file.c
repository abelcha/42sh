/*
** put_in_history.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/history
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon May 12 22:33:37 2014 chalie_a
** Last update Thu May 22 23:12:00 2014 chalie_a
*/

#include <unistd.h>
#include <fcntl.h>
#include "edit.h"
#include "sh.h"

int		add_in_history_file(t_line *line)
{
  int		fd;
  t_history	*tmp;
  t_history	*save;
  int		i;

  i = -1;
  tmp = line->sh->history;
  if ((fd = open("./.42sh_history", (O_RDWR | O_CREAT | O_TRUNC), 0777)) < 0)
    return (FAILURE);
  save = tmp->prev;
  while ((tmp = tmp->next) != line->sh->history)
    {
      if (++i < line->sh->hist_limit && tmp->data)
	{
	  write(fd, tmp->data, my_strlen(tmp->data));
	  write(fd, "\n", 1);
	}
      XFREE(tmp->data);
      XFREE(tmp->prev);
    }
  XFREE(save);
  XFREE(line);
  close(fd);
  return (SUCCESS);
}
