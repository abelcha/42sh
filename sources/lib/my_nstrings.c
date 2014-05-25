/*
** my_nstrings.c for Project-Master in /home/tovazm/rendu/42sh/42SH
** 
** Made by chalie_a
** Login   <abel.chalier@epitech.eu>
** 
** Started on  Thu May 22 11:37:18 2014 chalie_a
** Last update Thu May 22 11:57:39 2014 chalie_a
*/

#include <stdlib.h>

void		my_strncpy(char *dest, char *src, int n)
{
  int		i;

  i = -1;
  if (!dest || !src || n <= 0)
    return ;
  while (++i < n && src[i])
    dest[i] = src[i];
  dest[i] = 0;
}

char		*my_strndup(char *str, int n)
{
  char		*tmp;

  if (!str || n <= 0)
    return (NULL);
  if (!(tmp = calloc(n + 2, sizeof(char))))
    return (NULL);
  my_strncpy(tmp, str, n);
  return (tmp);
}
