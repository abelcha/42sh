/*
** tab_glob.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/line_edition
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed May 14 06:50:00 2014 chalie_a
** Last update Fri May 16 13:30:45 2014 chalie_a
*/

#include <glob.h>
#include <string.h>
#include "sh.h"
#include "edit.h"
#define	ARG	12
#define CMD	42

int			get_cols()
{
  struct winsize	w;

  if (ioctl(0, TIOCGWINSZ, &w) == -1)
    return (FAILURE);
  return (w.ws_col);
}

int			is_doublon(char *str, t_glob *root)
{
  t_glob		*tmp;

  tmp = root;
  while ((tmp = tmp->next) != root)
    {
      //printf("tamere = %s lol = %s\n", str, tmp->data);
      if (!my_strcmp(str, tmp->data))
	return (1);
    }
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

char		*get_fusion(char *path, char *word, int *len)
{
  char		*temp;

  *len =  strlen(path);
  temp = calloc(strlen(word) + *len + 4, sizeof(char));
  if (!temp)
    return (NULL);
  strcpy(temp, path);
  strcat(temp, word);
  return (temp);
}

void		check_match(char *temp, t_gb *gb, int len)
{
  glob_t	gl;

  glob(temp, 0, NULL, &gl);
  if (gl.gl_pathc == 1)
    add_glob(gb, gl.gl_pathv[0], len);
  temp[strlen(temp)] = '*';
}

int		get_data(char *path, char *word, t_gb *gb)
{
  char		*temp;
  glob_t	gl;
  int		len;
  int		i;

  i = -1;
  if (!(temp = get_fusion(path, word, &len)))
    return (FAILURE);
  check_match(temp, gb, len);
  //  printf("temp = %s\n", temp);
  glob(temp, 0, NULL, &gl);
  if (gl.gl_pathc <= 0)
    return (FAILURE);
  while (++i < gl.gl_pathc)
    if (add_glob(gb, gl.gl_pathv[i], len) == FAILURE)
      return (FAILURE);
  free(temp);
  globfree(&gl);
  return (SUCCESS);
}

int		get_command(char *word, t_line *line, t_gb *gb)
{
  char		**p_tab;
  char		*tmp;
  int		i;

  i = -1;
  p_tab = line->exe->env->paths;
  while (p_tab && p_tab[++i])
    get_data(p_tab[i], word, gb);
  return (SUCCESS);
}

char		*get_word(char *line, int pos)
{
  while (pos > 0)
    {
      if (line[pos] == ' ' || line[pos] == '\t')
	return (strdup(&line[pos]));
      --pos;
    }
  return (strdup(line));
}

int		bigger_len(t_glob *root)
{
  t_glob	*tmp;
  int		len;
  int		res;

  res = 0;
  tmp = root;
  while ((tmp = tmp->next) != root)
    if ((tmp->len = strlen(tmp->data)) > res)
      res = tmp->len;
  return (res);
}

void		write_and_blanks(int maxlen, int len, char *str)
{
  write(1, str, len);
  while (++len <= maxlen)
    CAP("nd");
}

int		yes_or_no(int total)
{
  char		buffer[1];

  printf("\nDisplay all %d possibilities ? (y/n)\n", total);
  while (42)
    if (read(0, &buffer, 1) <= 0)
      return (FAILURE);
    else if (buffer[0] == 'y')
      return (SUCCESS);
    else if (buffer[0] == 'n')
      return (FAILURE);
}

void		display_pos(t_gb *root, t_line *line)
{
  t_glob	*tmp;
  int		cols;
  int		maxlen;
  int		len;

  if (root->total > 42 && yes_or_no(root->total) == FAILURE)
    {
      replace_cursor(0, 6 + line->pos);
      return;
    }
  if ((cols = get_cols()) == FAILURE)
    return ;
  write(1, "\n", 1);
  maxlen = bigger_len(root->g);
  len = 0;
  tmp = root->g;
  while ((tmp = tmp->next) != root->g)
    {
      len += maxlen;
      if (len > (cols - maxlen + 1))
	{
	  write(1, "\n", 1);
	  len = 0;
	}
      write_and_blanks(maxlen, tmp->len, tmp->data);
      free(tmp->prev->data);
      free(tmp->prev);
    }
  write(1, "\n", 1);
  replace_cursor(0, line->pos + 6);
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

  type = CMD;
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
