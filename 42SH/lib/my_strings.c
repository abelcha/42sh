/*
** strings.c for Project-Master in /home/tovazm/rendu/42sh/42SH
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Tue May 20 14:51:11 2014 chalie_a
** Last update Tue May 20 14:54:03 2014 chalie_a
*/

#include <stdlib.h>

int		my_strlen(char *str)
{
  int		i;

  i = -1;
  if (!str)
    return (0);
  while (str[++i]);
  return (i);
}


char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (dest && src && src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  if (i != 0)
    dest[i] = '\0';
  return (dest);
}

char	*my_strdup(char *str)
{
  char	*newstr;

  newstr = calloc((my_strlen(str) + 1), sizeof(char));
  if (newstr)
    my_strcpy(newstr, str);
  return (newstr);
}
