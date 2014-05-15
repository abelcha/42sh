/*
** strings.c for minish in /home/chalie_a/rendu/PSU_2013_minishell1
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Wed Jan  1 03:15:53 2014 chalie_a
** Last update Sun Mar  9 16:40:06 2014 chalie_a
*/

#include "mysh.h"

int	my_strncmp(char *s1, char *s2, int nb)
{
  int	i;

  i = 0;
  while ((s1[i] || s2[i]) && i < nb)
    {
      if (s1[i] < s2[i])
        return (-1);
      if (s1[i] > s2[i])
        return (1);
      i = i + 1;
    }
  if ((s1[i] < s2[i]) && i < nb)
    return (-1);
  if ((s1[i] > s2[i]) && i < nb)
    return (1);
  return (0);
}

char	*my_strndup(char *str, int len)
{
  char	*buff;
  int	i;

  buff = x_malloc((len + 1) * sizeof (char));
  i = 0;
  while (i < len)
    {
      buff[i] = str[i];
      i++;
    }
  buff[len] = '\0';
  return (buff);
}
