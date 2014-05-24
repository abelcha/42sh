/*
** pre_parsing.c for Project-Master in /home/tovazm/rendu/42sh/42SH
** 
** Made by chalie_a
** Login   <abel.chalier@epitech.eu>
** 
** Started on  Mon May 19 17:25:33 2014 chalie_a
** Last update Fri May 23 10:54:03 2014 chalie_a
*/

#include <stdlib.h>
#include "sh.h"

int		pre_parsing(t_shell *sh)
{
  char		**stock;
  int		i;

  i = -1;
  sh->line->realloc_cpt = 0;
  sh->line->pos = 0;
  if (!(stock = to_tab(sh->line->line, 0, ' ')) || !(*stock[0]))
    return (FAILURE);
  while (stock[++i])
    if (parse_line(stock[i], sh) == FAILURE)
      return (FAILURE);
  if (sh->line->line_save)
    {
      XFREE(sh->line->line);
      sh->line->line = sh->line->line_save;
    }
  sh->line->line_save = NULL;
  double_free(&stock);
  return (SUCCESS);
}
