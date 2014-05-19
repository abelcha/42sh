/*
** get_opti.c for get_next_line in /home/chalie_a/rendu/PSU_2013_minishell1
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sat Dec 28 05:44:46 2013 chalie_a
** Last update Sun May  4 17:35:24 2014 chalie_a
*/

#include <stdlib.h>

char	**to_tab(char *s, int cpt, char sep)
{
  int	i;
  int	j;
  int	len;
  char	**tab;

  i = -1;
  while ((s[++i] == sep || s[i] == '\t'));
  len = i - 1 ;
  while ((s[++len] != sep && s[len] != '\t' && s[len]));
  j = len - 1;
  while ((s[++j] == sep || s[j] == '\t'));
  tab = (s[j] == '\0' ? calloc((cpt + 10), sizeof(char *)) : NULL);
  if (s[j] != '\0')
    tab = to_tab(&s[len], cpt + 1, sep);
  if (!(tab[cpt] = calloc(((len - i) + 10), sizeof(char))))
    return (NULL);
  j = 0;
  while (i < len && (tab[cpt][j++] = s[i++]));
  return (tab);
}
