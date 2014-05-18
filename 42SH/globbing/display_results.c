/*
** tab_glob.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/line_edition
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed May 14 06:50:00 2014 chalie_a
** Last update Sun May 18 04:04:28 2014 chalie_a
*/

#include <glob.h>
#include <string.h>
#include "sh.h"
#include "edit.h"

int			get_cols()
{
  struct winsize	w;

  if (ioctl(0, TIOCGWINSZ, &w) == -1)
    return (FAILURE);
  return (w.ws_col);
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

void		print_list(int maxlen, t_glob *root, int cols)
{
  int		len;
  t_glob	*tmp;

  len = 0;
  tmp = root;
  while ((tmp = tmp->next) != root)
    {
      len += maxlen;
      if (len > (cols - maxlen + 1))
	{
	  write(1, "\n", 1);
	  len = 0;
	}
      write_and_blanks(maxlen, tmp->len, tmp->data);
    }
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
  print_list(maxlen, root->g, cols);
  write(1, "\n", 1);
  replace_cursor(0, line->pos + 6);
}

