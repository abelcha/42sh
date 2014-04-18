/*
** my_memset.c for shell in /home/chalie_a/rendu/PSU_2013_minishell1/sources
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Wed Jan  1 19:27:17 2014 chalie_a
** Last update Wed Jan  1 19:27:17 2014 chalie_a
*/

#include <stdlib.h>

char	*my_memset(char *s, char c, int size)
{
  int	i;

  i = 0;
  while (i < size)
    s[i++] = c;
  return (s);
}

char	**my_meminit(char **s, int size)
{
  int	i;

  i = 0;
  while (i < size)
    s[i++] = NULL;
  return (s);
}
