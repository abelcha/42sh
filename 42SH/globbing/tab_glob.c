/*
** tab_glob.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/line_edition
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed May 14 06:50:00 2014 chalie_a
** Last update Sun May 18 06:03:06 2014 chalie_a
*/

#include <glob.h>
#include <string.h>
#include "sh.h"
#include "edit.h"

int			get_partial_matching(char *s1, char *s2)
{
  int			i;

  i = -1;
  if (!s1)
    return (strlen(s2));
  while (s1[++i] && s2[i])
    if (s1[i] != s2[i])
      break;
  return (i);
}

int			is_doublon(char *str, t_glob *root)
{
  t_glob		*tmp;

  tmp = root;
  while ((tmp = tmp->next) != root)
    if (!my_strcmp(str, tmp->data))
      return (1);
  return (0);
}

int			add_glob(t_gb *root, char *data, int len)
{
  t_glob		*newelem;
  t_glob		*elem;

  elem = root->g;
  if (is_doublon(&data[len], root->g))
    return (SUCCESS);
  if (!(newelem = calloc(1, sizeof(t_glob))))
    return (FAILURE);
  if (!(newelem->data = strdup(&data[len])))
    return (FAILURE);
  ++(root->total);
  newelem->prev = elem->prev;
  newelem->next = elem;
  elem->prev->next = newelem;
  elem->prev = newelem;
  if (root->part_match - root->word_len)
    root->part_match = get_partial_matching(newelem->prev->data,
					    newelem->data);
  return (SUCCESS);
}

t_glob			*init_glob()
{
  t_glob		*root;

  if (!(root = calloc(1, sizeof(t_glob))))
    return (NULL);
  root->prev = root;
  root->next = root;
  return (root);
}

void		remplace_it(t_line *line, t_gb *gb, int start)
{
  int		oldpos;

  oldpos = line->pos;
  strncpy(&line->line[start], gb->g->next->data, gb->part_match);
  line->pos = strlen(line->line);
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

void		free_glob_list(t_gb *gb)
{
  t_glob	*tmp;
  t_glob	*save;

  tmp = gb->g;
  save = tmp->prev;
  while ((tmp = tmp->next) != gb->g)
    {
      x_free(tmp->prev->data);
      x_free(tmp->prev);
    }
  x_free(save->data);
  x_free(save);
  x_free(gb->word);
  x_free(gb);
}

void		tab_glob(t_line *line)
{
  t_gb		*gb;
  int		type;
  int		start;

  if (!(gb = calloc(1, sizeof(t_gb))) || !(gb->g = init_glob()))
    return ;
  if (!(gb->word = get_word(line->line, line->pos, &start)))
    return ;
  type = get_type(line->line, start);
  gb->part_match = -1;
  gb->word_len = strlen(gb->word);
  if (type == CMD)
    get_command(gb->word, line, gb);
  else
    get_data("", gb->word, gb);
  if (gb->total == 0);
  else if (gb->total == 1 || (gb->part_match - gb->word_len) > 0)
    remplace_it(line, gb, start);
  else if (line->tab_flag)
    display_pos(gb, line);
  else
    line->tab_flag = 1;
  free_glob_list(gb);
  clear_and_display(line);
}
