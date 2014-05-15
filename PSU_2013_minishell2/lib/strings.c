/*
** strings.c for minish in /home/chalie_a/rendu/PSU_2013_minishell1
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Wed Jan  1 03:15:53 2014 chalie_a
** Last update Sun Mar  9 16:40:13 2014 chalie_a
*/

#include "mysh.h"

char	*my_strcat(char *s1, char *s2)
{
  char	*new;
  int	i;
  int	j;
  int	len;

  i = 0;
  j = 0;
  len = my_strlen(s1) + my_strlen(s2);
  new = x_malloc((len + 1) * sizeof(char));
  my_memset(new, '\0', len + 1);
  while (s1[i])
    {
      new[i] = s1[i];
      i++;
    }
  while (s2[j])
    {
      new[i + j] = s2[j];
      j++;
    }
  return (new);
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

  newstr = x_malloc((my_strlen(str) + 8) * sizeof(char *));
  if (newstr)
    my_strcpy(newstr, str);
  return (newstr);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    i++;
  return (i);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	error;
  int	nbs1;
  int	nbs2;

  nbs1 = 0;
  nbs2 = 0;
  error = 0;
  i = 0;
  nbs1 = my_strlen(s1);
  nbs2 = my_strlen(s2);
  while (s1 && s2 && s1[i] == s2[i] && (i != nbs1 || i !=nbs2))
    {
      i = i + 1;
      if (nbs1 - nbs2 == 0 && i == nbs1)
        return (0);
    }
  if (s1 && s2 && s1[i] != s2[i])
    {
      error = s1[i] - s2[i];
      return (error);
    }
  return (0);
}
