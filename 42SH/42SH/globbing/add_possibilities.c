/*
** tab_glob.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/line_edition
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed May 14 06:50:00 2014 chalie_a
** Last update Thu May 22 11:58:41 2014 chalie_a
*/

#include <stdlib.h> 
#include <glob.h>
#include <string.h>
#include "sh.h"
#include "edit.h"

static int			get_partial_matching(const char *s1,
						     const char *s2)
{
  int				i;

  i = -1;
  if (!s1)
    return (my_strlen(s2));
  while (s1[++i] && s2[i])
    if (s1[i] != s2[i])
      break;
  return (i);
}

static int			is_doublon(char *str, t_glob *root)
{
  t_glob			*tmp;

  tmp = root;
  while ((tmp = tmp->next) != root)
    if (!my_strcmp(str, tmp->data))
      return (1);
  return (0);
}

static void			fill_glob_elem(t_glob *elem, t_glob *newelem,
					       t_gb *root)
{
  ++(root->total);
  newelem->prev = elem->prev;
  newelem->next = elem;
  elem->prev->next = newelem;
  elem->prev = newelem;
  if (root->part_match - my_strlen(root->word))
    root->part_match =
      get_partial_matching(newelem->prev->data, newelem->data);
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
  if (!(newelem->data = my_strdup(&data[len])))
    return (FAILURE);
  fill_glob_elem(elem, newelem, root);
  return (SUCCESS);
}
