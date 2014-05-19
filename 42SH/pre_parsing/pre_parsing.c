/*
** pre_parsing.c for Project-Master in /home/tovazm/rendu/42sh/42SH
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon May 19 17:25:33 2014 chalie_a
** Last update Mon May 19 19:56:45 2014 chalie_a
*/

#include <stdio.h>
#include "sh.h"
#include "parser.h"

int		safe_joint(t_line *line, char *s2)
{
  int		i;
  int		j;
  char		*s;

  s = line->line_save;
  i = -1;
  while (s2[++i])
    {
      if (line->pos == line->realloc_cpt * MEM_POOL)
	{
	  if (!(s = realloc(s, ++(line->realloc_cpt) * MEM_POOL)))
	    return (FAILURE);
	}
      s[line->pos] = s2[i];
      (line->pos)++;
    }
  s[line->pos] = ' ';
  s[++line->pos] = 0;
  line->line_save = s;
  return (SUCCESS);
}

int		add_in_buffer(char **stock, t_line *line)
{
  int		j;

  j = -1;
  while (stock[++j])
    if (safe_joint(line, stock[j]) == FAILURE)
      return (FAILURE);
  return (SUCCESS);
}

int		parse_line(char *str, t_shell *sh)
{
  char		**tmp;

  if ((tmp = is_an_alias(str, sh)))
    return (add_in_buffer(tmp, sh->line));
  return (safe_joint(sh->line, str));
}

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
  sh->line->line = sh->line->line_save;
  sh->line->line_save = NULL;
  printf("line = %s\n", sh->line->line);

}
