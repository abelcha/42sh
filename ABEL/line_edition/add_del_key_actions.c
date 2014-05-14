/*
** add_del_key_actions.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/edit_line
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon May 12 21:06:09 2014 chalie_a
** Last update Tue May 13 00:34:17 2014 chalie_a
*/

#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include "edit.h"

static void		add_char_in_tab(const char c, char *str, const int pos)
{
  int			i;

  if (pos < 0)
    return ;
  i = strlen(str);
  while (i >= pos)
    {
      str[i + 1] = str[i];
      --i;
    }
  str[pos] = c;
}

static void		del_char_in_tab(char *str, int pos)
{
  int			i;

  i = strlen(str);
  while (pos < i)
    {
      str[pos] = str[pos + 1];
      ++pos;
    }
}

void		clear_and_display(t_line *line)
{
  int			i;

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

void			delete_char(t_line *line)
{
  if (line->pos <= 0)
    return ;
  del_char_in_tab(line->line, line->pos - 1);
  CAP("le");
  line->pos--;
  line->line_len--;
  clear_and_display(line);
}

void			add_char(t_line *line)
{
  add_char_in_tab(line->key, line->line, line->pos);
  CAP("nd");
  line->pos++;
  line->line_len++;
  clear_and_display(line);
}
