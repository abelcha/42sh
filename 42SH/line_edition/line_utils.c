/*
** line_utils.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/line_edition
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed May 14 16:58:52 2014 chalie_a
** Last update Wed May 14 17:01:28 2014 chalie_a
*/

#include <unistd.h>
#include "edit.h"

void		clear_and_display(t_line *line)
{
  int		i;

  i = -2;
  CAP("sc");
  CAP("dl");
  while (++i < (line->line_len + line->p_size))
    CAP("le");
  i = 0;
  write(1, line->prompt, line->p_size);
  write(1, line->line, line->line_len);
  CAP("rc");
}

void		replace_cursor(int oldpos, int newpos)
{
  int		delta;

  delta = oldpos - newpos;
  while (delta < 0)
    {
      CAP("nd");
      ++delta;
    }
  while (delta > 0)
    {
      CAP("le");
      --delta;
    }
}
