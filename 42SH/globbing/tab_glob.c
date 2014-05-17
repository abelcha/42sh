/*
** tab_glob.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/line_edition
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed May 14 06:50:00 2014 chalie_a
** Last update Sat May 17 01:52:22 2014 chalie_a
*/

#include <glob.h>
#include <string.h>
#include "sh.h"
#include "edit.h"

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

void		remplace_it(t_line *line, t_gb *gb)
{
  int		oldpos;

  oldpos = line->pos;
  strcpy(line->line, gb->g->next->data);
  line->pos = strlen(gb->g->next->data);
  line->line_len = line->pos;
  replace_cursor(oldpos, line->pos);
}

void		tab_glob(t_line *line)
{
  t_gb		*gb;
  int		type;
  char		*new_word;
  char		*word;

  type = get_type(line->line, line->pos);
  return;
  if (!(gb = calloc(1, sizeof(t_gb))) || !(gb->g = init_glob()))
    return ;
  if (!(word = get_word(line->line, line->pos)))
    return ;
  get_command(word, line, gb);
  if (gb->total == 0)
    return ;
  else if (gb->total == 1)
    remplace_it(line, gb);
  else if (line->tab_flag)
    display_pos(gb, line);
  else
    line->tab_flag = 1;
  // printf("total = %d\n", gb->total);
  clear_and_display(line);
}
