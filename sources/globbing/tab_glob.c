/*
** tab_glob.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/line_edition
** 
** Made by chalie_a
** Login   <abel.chalier@epitech.eu>
** 
** Started on  Wed May 14 06:50:00 2014 chalie_a
** Last update Sat May 24 18:26:23 2014 chalie_a
*/

#include <stdlib.h>
#include <glob.h>
#include <string.h>
#include "sh.h"
#include "edit.h"

static t_glob		*init_glob()
{
  t_glob		*root;

  if (!(root = calloc(1, sizeof(t_glob))))
    return (NULL);
  root->prev = root;
  root->next = root;
  return (root);
}

static void		remplace_it(t_line *line, t_gb *gb,
				    const int start)
{
  int			oldpos;

  oldpos = line->pos;
  my_strncpy(&line->line[start], gb->g->next->data, gb->part_match);
  line->pos = my_strlen(line->line);
  if (gb->total == 1)
    {
      if (is_dir(gb->g->next->data))
	line->line[line->pos] = '/';
      else
	line->line[line->pos] = ' ';
      ++line->pos;
    }
  line->line_len = line->pos;
  replace_cursor(oldpos, line->pos);
}

static void		free_glob_list(t_gb *gb)
{
  t_glob		*tmp;
  t_glob		*save;

  tmp = gb->g;
  save = tmp->prev;
  while ((tmp = tmp->next) != gb->g)
    {
      XFREE(tmp->prev->data);
      XFREE(tmp->prev);
    }
  XFREE(save->data);
  XFREE(save);
  XFREE(gb->word);
  XFREE(gb);
}

void			tab_glob(t_line *line)
{
  t_gb			*gb;
  int			type;
  int			start;

  if (!(gb = calloc(1, sizeof(t_gb))) || !(gb->g = init_glob()))
    return ;
  if (!(gb->word = get_word(line->line, line->pos, &start)))
    return ;
  type = get_type(line->line, start);
  gb->part_match = -1;
  type == CMD ? get_command(gb->word, line, gb) : get_data("", gb->word, gb);
  if (gb->total == 1 || (gb->part_match - my_strlen(gb->word)) > 0)
    remplace_it(line, gb, start);
  else if (gb->total && line->tab_flag)
    display_pos(gb, line);
  else if (gb->total)
    line->tab_flag = 1;
  free_glob_list(gb);
  clear_and_display(line);
}
