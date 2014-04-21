/*
** get_next_line.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Apr 20 17:05:51 2014 chalie_a
** Last update Sun Apr 20 21:12:58 2014 chalie_a
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"

static char             buffer[BUFFER_SIZE];
static int		buffer_size;

static char		*free_and_return(char *s)
{
  if (s)
    free(s);
  return (0);
}

static signed int	findchar(char c, char *s, int give_me_length)
{
  int			i;

  i = 0;
  if (s == 0)
    return (give_me_length ? 0 : -1);
  while (s[i] || give_me_length)
    {
      if (s[i] == c)
	return (i);
      i += 1;
    }
  return (-1);
}

static char		*superstr(char *s)
{
  char			*str;
  char			*w;
  int			i;

  if (s == 0 && buffer[0] == 0)
    return (0);
  if ((str = malloc(sizeof(char) * (STRLEN(s) + STRLEN(buffer) + 1))) == 0)
    return (free_and_return(s));
  w = str;
  if (s)
    {
      i = 0;
      while (s[i])
	*(w++) = s[i++];
      free_and_return(s);
    }
  i = 0;
  while (buffer[i] && i < buffer_size)
    *(w++) = buffer[i++];
  *w = 0;
  return (str);
}

static char		*conclude(char *line, int j)
{
  int			i;

  i = j + 1;
  buffer_size = 0;
  while (line[i])
    buffer[buffer_size++] = line[i++];
  line[j] = 0;
  return (line);
}

char			*gnl(const int fd)
{
  char			*line;
  int			j;

  if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE < 1)
    return (0);
  line = superstr(0);
  while ((j = FINDCHAR('\n', line)) == -1)
    {
      if ((buffer_size = read(fd, buffer, BUFFER_SIZE)) == -1)
	return (free_and_return(line));
      else if (buffer_size == 0)
	{
	  if (line && line[0] == 0)
	    return (free_and_return(line));
	  else
	    return (line);
	}
      else if ((line = superstr(line)) == 0)
	return (free_and_return(line));
    }
  return (conclude(line, j));
}
