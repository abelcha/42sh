/*
** tab_glob.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/line_edition
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed May 14 06:50:00 2014 chalie_a
** Last update Mon May 19 13:55:47 2014 chalie_a
*/

#include <glob.h>
#include <string.h>
#include "sh.h"
#include "edit.h"

int		get_type(char *line, int pos)
{
  while (pos > 0 && line[pos] != '|' && line[pos] != ';' && line[pos] != '&')
    {
      if (line[pos] == ' ' || line[pos] == '\t')
	return (ARG);
      --pos;
    }
  return (CMD);
}

char		*get_word(char *line, int pos, int *type)
{
  int		save;

  save = pos;
  if (pos > (BUFF_LINE))
    return (NULL);
  while (pos > 0 && line[pos] != '|' && line[pos] != ';' && line[pos] != '&')
    {
      if (line[pos] == ' ' || line[pos] == '\t')
	{
	  *type = pos + 1;
	  break ;
	}
      --pos;
    }
  if (pos == 0)
    *type = pos;
  return (strndup(&line[*type], save - pos));
}
