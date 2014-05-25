/*
** pre_parsing.c for Project-Master in /home/tovazm/rendu/42sh/42SH
** 
** Made by chalie_a
** Login   <abel.chalier@epitech.eu>
** 
** Started on  Mon May 19 17:25:33 2014 chalie_a
** Last update Sun May 25 16:08:39 2014 chalie_a
*/

#include <stdlib.h>
#include <stdio.h>
#include "sh.h"
#include "parser.h"

static int		safe_joint(t_line *line, const char *s2)
{
  int			i;
  char			*s;

  s = line->line_save;
  i = -1;
  while (s2[++i])
    {
      if (line->pos >= line->realloc_cpt * _MEM_POOL)
	if (!(s = realloc(s, ++(line->realloc_cpt) * _MEM_POOL + 4)))
	  return (FAILURE);
      s[line->pos] = s2[i];
      (line->pos)++;
    }
  s[line->pos] = ' ';
  s[++line->pos] = 0;
  line->line_save = s;
  return (SUCCESS);
}

static int		add_in_buffer(char **stock, t_line *line, int flag)
{
  int			j;

  j = -1;
  while (stock[++j])
    {
      if (safe_joint(line, stock[j]) == FAILURE)
	return (FAILURE);
      if (flag)
      	XFREE(stock[j]);
    }
  if (flag)
    XFREE(stock);
  return (SUCCESS);
}

static int		dollar_sign(char *str, t_shell *sh)
{
  char			*tmp;
  t_env_dll		*env_tmp;

  if (str[1] == '?' && (tmp = my_itoa(sh->exe->return_value % 256)))
    return (safe_joint(sh->line, tmp));
  if ((env_tmp = search_for_env_variable(&str[1], sh->exe->env->env_dll)))
    return (safe_joint(sh->line, env_tmp->value));
  return (safe_joint(sh->line, str));
}

static int		history_find(char *str, t_shell *sh)
{
  t_history		*tmp;
  int			nbr;
  int			i;

  i = -1;
  if ((nbr = my_atoi(&str[1])) <= 0)
    return (safe_joint(sh->line, str));
  tmp = sh->history;
  while ((tmp = tmp->next) != sh->history && ++i < nbr);
  printf("%d--> %s\n", nbr, tmp->data);
  return (safe_joint(sh->line, tmp->data));
}

int			parse_line(char *str, t_shell *sh)
{
  char			**tmp;

  if ((tmp = is_globbing(str)))
    return (add_in_buffer(tmp, sh->line, 1));
  if ((tmp = is_an_alias(str, sh)))
    return (add_in_buffer(tmp, sh->line, 0));
  if (*str == '$' && str[1])
    return (dollar_sign(str, sh));
  if (*str == '!' && str[1])
    return (history_find(str, sh));
  return (safe_joint(sh->line, str));
}
