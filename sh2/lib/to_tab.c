/*
** get_opti.c for get_next_line in /home/chalie_a/rendu/PSU_2013_minishell1
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sat Dec 28 05:44:46 2013 chalie_a
** Last update Sun Mar  9 18:35:08 2014 chalie_a
*/

#include <stdlib.h>
#include "mysh.h"

char	**to_tab(char *s, int cpt, char sep)
{
  int	i;
  int	j;
  int	len;
  char	**tab;

  i = 0;
  while ((s[i] == sep || s[i] == '\t'))
    i++;
  len = i;
  while ((s[len] != sep && s[len] != '\t' && s[len]))
    len++;
  j = len;
  while ((s[j] == sep || s[j] == '\t'))
    j++;
  tab = (s[j] == '\0' ? x_malloc((cpt + 4) * sizeof(*tab)) : NULL);
  if (s[j] == '\0')
    tab[cpt + 1] = NULL;
  else
    tab = to_tab(&s[len], cpt + 1, sep);
  tab[cpt] = x_malloc(((len - i) + 4) * sizeof(**tab));
  j = 0;
  while (i < len)
    tab[cpt][j++] = s[i++];
  tab[cpt][j] = '\0';
  return (tab);
}
