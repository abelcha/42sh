/*
** init.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/edit_line
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon May 12 15:42:51 2014 chalie_a
** Last update Mon May 19 18:44:54 2014 beau_v
*/

#include "edit.h"

static const int	key_tab[AK_NB] = {K_LEFT,
						  K_RIGHT,
						  K_DEL,
						  K_UP,
						  K_DOWN,
						  K_TAB,
						  CTRL_A,
						  CTRL_E,
						  CTRL_B,
						  ALT_B,
						  CTRL_F,
						  ALT_F,
						  CTRL_E,
						  CTRL_U,
						  CTRL_K,
						  CTRL_W,
						  CTRL_L,
						  ALT_I};

static void		move_left(t_line *line)
{
  if (line->pos <= 0)
    return ;
  CAP("le");
  line->pos--;
}
static void		move_right(t_line *line)
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
    while (++i < (6 + line->pos))		//6 IS FUCKIN TEMPORARY !!
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
  static const t_ak	act_tab[AK_NB] = {move_left, move_right, delete_char,
					  go_prev, go_next, tab_glob, move_to_start,
					  move_to_end, move_left, move_back_word,
					  move_right, move_fwd_word, delete_word,
					  delete_until_start, delete_until_end,
					  delete_word, clear_scr, real_tab};

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

