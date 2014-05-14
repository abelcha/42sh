/*
** init.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/edit_line
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon May 12 15:42:51 2014 chalie_a
** Last update Mon May 12 21:20:45 2014 chalie_a
*/

#include "edit.h"

static void			move_left(t_line *line)
{
  if (line->pos <= 0)
    return ;
  CAP("le");
  line->pos--;
}
static void			move_right(t_line *line)
{
  if (line->pos >= line->line_len)
    return ;
  CAP("nd");
  line->pos++;
}

void				do_key_actions(t_line *line)
{
  static const t_ak		act_tab[AK_NB] = {move_left, move_right, 
						  delete_char, go_prev,
						  go_next};
  static const int		key_tab[AK_NB] = {K_LEFT, K_RIGHT,
						  K_DEL, K_UP, K_DOWN};
  int				i;

  i = -1;
  while (++i < AK_NB)
    if (line->key == key_tab[i])
      act_tab[i](line);
  if (VALID_CHAR(line->key))
    add_char(line);
}

