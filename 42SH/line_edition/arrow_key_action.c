/*
** init.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/edit_line
** 
** Made by chalie_a
** Login   <abel.chalier@epitech.eu>
** 
** Started on  Mon May 12 15:42:51 2014 chalie_a
** Last update Sat May 24 18:16:53 2014 chalie_a
*/

#include "edit.h"

extern const int	key_tab[AK_NB];
extern const t_ak	act_tab[AK_NB];

void			move_left(t_line *line)
{
  if (line->pos <= 0)
    return ;
  CAP("le");
  line->pos--;
}

void			move_right(t_line *line)
{
  if (line->pos >= line->line_len)
    return ;
  CAP("nd");
  line->pos++;
}

void			clear_scr(t_line *line)
{
  int			i;

  i = -1;
    CAP("cl");
    clear_and_display(line);
    while (++i < (6 + line->pos))
      CAP("nd");
}

void			real_tab(t_line *line)
{
  line->key = '\t';
  add_char(line);
}

void			do_key_actions(t_line *line)
{
  int			i;

  i = -1;
  while (++i < AK_NB)
    {
      if (line->key == key_tab[i])
	{
	  act_tab[i](line);
	  return ;
	}
    }
  if (VALID_CHAR(line->key))
    add_char(line);
}

