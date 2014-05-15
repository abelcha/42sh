/*
** my_strcat.c for my_strcat in /home/chalie_a/rendu/Piscine-C-lib/my
** 
** Made by chalie_a
** Login   <chalie_a@epitech.net>
** 
** Started on  Mon Oct 21 11:42:33 2013 chalie_a
** Last update Wed Nov 27 11:15:16 2013 chalie_a
*/

#include "mysh.h"

char	*my_pathcat(char *s1, char *s2)
{
  char	*new;
  int	i;
  int	j;
  int	len;

  i = 0;
  j = 0;
  len = my_strlen(s1) + my_strlen(s2);
  new = x_malloc((len + 2) * sizeof(char));
  my_memset(new, '\0', len + 2);
  while (s1[i])
    {
      new[i] = s1[i];
      i++;
    }
  new[i] = '/';
  i++;
  while (s2[j])
    {
      new[i + j] = s2[j];
      j++;
    }
  return (new);
}
