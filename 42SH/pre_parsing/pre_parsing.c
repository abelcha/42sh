/*
** pre_parsing.c for Project-Master in /home/tovazm/rendu/42sh/42SH
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon May 19 17:25:33 2014 chalie_a
** Last update Tue May 20 14:54:35 2014 chalie_a
*/

#include <stdlib.h>
#include <stdio.h>
#include <glob.h>
#include "sh.h"
#include "parser.h"

int		safe_joint(t_line *line, char *s2)
{
  int		i;
  char		*s;

  s = line->line_save;
  i = -1;
  while (s2[++i])
    {
      if (line->pos >= line->realloc_cpt * _MEM_POOL)
	if (!(s = realloc(s, ++(line->realloc_cpt) * _MEM_POOL + 1024)))
	  return (FAILURE);
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

int		dollar_sign(char *str, t_shell *sh)
{
  char		*tmp;
  t_env_dll	*env_tmp;

  if (str[1] == '?' && (tmp = my_itoa(sh->exe->return_value % 256)))
    return (safe_joint(sh->line, tmp));
  if ((env_tmp = search_for_env_variable(&str[1], sh->exe->env->env_dll)))
    return (safe_joint(sh->line, env_tmp->value));
  return (safe_joint(sh->line, str));
}

int		history_find(char *str, t_shell *sh)
{
  t_history	*tmp;
  int		nbr;
  int		i;

  i = -1;
  if ((nbr = my_atoi(&str[1])) <= 0)
    return (safe_joint(sh->line, str));
  tmp = sh->history;
  while ((tmp = tmp->next) != sh->history && ++i < nbr);
  printf("%d--> %s\n", nbr, tmp->data);
  return (safe_joint(sh->line, tmp->data));
}

char		**is_globbing(char *str)
{
  glob_t	gl;
  int		i;
  char		**tmp;

  i = -1;
  glob(str, 0, NULL, &gl);
  if (gl.gl_pathc <= 0)
    return (NULL);
  if (!(tmp = calloc((int)gl.gl_pathc + 2, sizeof(char *))))
    return (NULL);
  while (++i < (int)gl.gl_pathc)
    if (!(tmp[i] = my_strdup(gl.gl_pathv[i])))
      return (NULL);
  tmp[i] = NULL;
  globfree(&gl);
  return (tmp);
}

int		parse_line(char *str, t_shell *sh)
{
  char		**tmp;

  if ((tmp = is_globbing(str)))
    return (add_in_buffer(tmp, sh->line));
  if ((tmp = is_an_alias(str, sh)))
    return (add_in_buffer(tmp, sh->line));
  if (*str == '$' && str[1])
    return (dollar_sign(str, sh));
  if (*str == '!' && str[1])
    return (history_find(str, sh));
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
  if (sh->line->line_save)
    sh->line->line = sh->line->line_save;
  sh->line->line_save = NULL;
  return (SUCCESS);
}
