/*
** my_strlen.c for my_strlen in /home/chalie_a/rendu/Piscine-C-lib/my
** 
** Made by chalie_a
** Login   <chalie_a@epitech.net>
** 
** Started on  Mon Oct 21 11:45:34 2013 chalie_a
** Last update Tue May 20 14:55:49 2014 chalie_a
*/

#include <stdlib.h>

static char	**parsing(char **tab, char *str, int nb, char c)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  while (j < nb)
    {
      k = 0;
      while (str && str[i] != '\0' && str[i] != c)
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

static int	count_len(char *str, char c, int flag)
{
  static int	par;
  int		i;

  i = 0;
  if (flag == 0)
    par = 0;
  while (str && str[par] != '\0' && str[par] != c)
    {
      i++;
      par++;
    }
  par++;
  return (i);
}

static int	count_word(char *str, char c)
{
  int		i;
  int		count;

  i = 0;
  count = 1;
  while (str && str[i] != '\0')
    {
      if (str[i] == c)
	count++;
      i++;
    }
  return (count);
}

char		**get_paths(char *str, char c)
{
  int		i;
  int		nb;
  char		**tab;

  i = 0;

  nb = count_word(str, c);
  if (!(tab = calloc((nb + 1), sizeof(str))))
    return (NULL);
  while (i < nb)
    {
      if (!(tab[i] = calloc(count_len(str, c, i) + 2, sizeof(char))))
	return (NULL);
      i++;
    }
  parsing(tab, str, nb, c);
  return (tab);
}

