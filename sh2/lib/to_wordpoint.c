/*
** my_strlen.c for my_strlen in /home/chalie_a/rendu/Piscine-C-lib/my
** 
** Made by chalie_a
** Login   <chalie_a@epitech.net>
** 
** Started on  Mon Oct 21 11:45:34 2013 chalie_a
** Last update Mon Oct 21 11:45:36 2013 chalie_a
*/

#include <stdlib.h>
#include "mysh.h"

char	**parsing(char **tab, char *str, int nb, char c)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  while (j < nb)
    {
      k = 0;
      while (str[i] != '\0' && str[i] != c)
	{
	  tab[j][k] = str[i];
	  k++;
	  i++;
	}
      tab[j][k] = '/';
      tab[j][k + 1] = '\0';
      j++;
      i++;
    }
  tab[j] = NULL;
  return (tab);
}

int		count_len(char *str, char c, int flag)
{
  static int	par;
  int		i;

  i = 0;
  if (flag == 0)
    par = 0;
  while (str[par] != '\0' && str[par] != c)
    {
      i++;
      par++;
    }
  par++;
  return (i);
}

int		count_word(char *str, char c)
{
  int		i;
  int		count;

  i = 0;
  count = 1;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	count++;
      i++;
    }
  return (count);
}

char	**to_wordpoint(char *str, char c)
{
  int	i;
  int	nb;
  char	**tab;

  i = 0;
  nb = count_word(str, c);
  tab = x_malloc((nb + 1) * sizeof(str));
  while (i < nb)
    {
      tab[i] = x_malloc((count_len(str, c, i) + 2) * sizeof(*str));
      i++;
    }
  parsing(tab, str, nb, c);
  return (tab);
}
