/*
** tab_glob.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/line_edition
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed May 14 06:50:00 2014 chalie_a
** Last update Thu May 22 23:22:08 2014 chalie_a
*/

#include <stdlib.h>
#include <glob.h>
#include <string.h>
#include "sh.h"
#include "edit.h"

static char		*get_fusion(char *path, char *word, int *len)
{
  char			*temp;

  *len =  my_strlen(path);
  temp = calloc(my_strlen(word) + *len + 4, sizeof(char));
  if (!temp)
    return (NULL);
  my_strcpy(temp, path);
  my_strcat(temp, word);
  return (temp);
}

static void		check_match(char *temp, t_gb *gb, int len, char flag)
{
  glob_t		gl;

  if (flag)
    {
      glob(temp, 0, NULL, &gl);
      if (gl.gl_pathc == 1)
	add_glob(gb, gl.gl_pathv[0], len);
    }
  temp[my_strlen(temp)] = '*';
}

int		get_data(char *path, char *word, t_gb *gb)
{
  char	      	*temp;
  glob_t	gl;
  int		len;
  int		i;

  i = -1;
  if (!(temp = get_fusion(path, word, &len)))
    return (FAILURE);
  check_match(temp, gb, len, *path);
  glob(temp, GLOB_TILDE_CHECK, NULL, &gl);
  XFREE(temp);
  if (gl.gl_pathc <= 0)
    return (FAILURE);
  while (++i < (int)gl.gl_pathc)
    if (add_glob(gb, gl.gl_pathv[i], len) == FAILURE)
      return (FAILURE);
  globfree(&gl);
  return (SUCCESS);
}

int		get_command(char *word, t_line *line, t_gb *gb)
{
  char		**p_tab;
  int		i;

  i = -1;
  p_tab = line->sh->exe->env->paths;
  while (p_tab && p_tab[++i])
    get_data(p_tab[i], word, gb);
  return (SUCCESS);
}
