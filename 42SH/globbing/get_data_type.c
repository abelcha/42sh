/*
** tab_glob.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/line_edition
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed May 14 06:50:00 2014 chalie_a
** Last update Sat May 17 01:51:43 2014 chalie_a
*/

#include <glob.h>
#include <string.h>
#include "sh.h"
#include "edit.h"

int		get_type(char *line, int pos)
{

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
