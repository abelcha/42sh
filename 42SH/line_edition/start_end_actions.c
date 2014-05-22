/*
** start_end_actions.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/line_edition
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed May 14 06:53:32 2014 chalie_a
** Last update Wed May 21 22:26:50 2014 chalie_a
*/

#include "sh.h"
#include "edit.h"

void		move_to_start(t_line *line)
{
  while (line->pos > 0)
    {
      --line->pos;
      CAP("le");
    }
}

void		move_to_end(t_line *line)
{
  while (line->pos < line->line_len)
    {
      ++line->pos;
      CAP("nd");
    }
}

void		delete_until_start(t_line *line)
{
  int		j;
  int		i;

  j = -1;
  i = line->pos - 1;
  replace_cursor(line->pos, 0);
  while (++i < line->line_len)
    line->line[++j] = line->line[i];
  my_memset(&(line->line)[j + 1], 0, line->line_len - j);
  line->line_len -= line->pos;
  while (++i < (line->line_len - line->pos))
    CAP("le");
  line->pos = 0;
  clear_and_display(line);
}

void		delete_until_end(t_line *line)
{
  int		i;

  i = line->pos - 1;
  while (++i < line->line_len)
    line->line[i] = '\0';
  line->line_len = line->pos;
  clear_and_display(line);
}
