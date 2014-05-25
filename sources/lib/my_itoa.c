/*
** my_itoa.c for shell in /home/chalie_a/rendu/PSU_2013_minishell1/sources
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sat Dec 28 05:45:26 2013 chalie_a
** Last update Tue May 20 09:19:18 2014 chalie_a
*/

#include <stdlib.h>

char	*my_itoa(int nbr)
{
  char	*buffer;
  int	i;
  int	power;

  power = 10;
  i = 0;
  while ((nbr / power) > 0)
    {
      power = power * 10;
      i++;
    }
  if (!(buffer = calloc (10, sizeof(char))))
    return (NULL);
  power = i;
  buffer[i + 1] = '\0';
  while (i >= 0)
    {
      buffer[i] =  (nbr - ((nbr/10) * 10) + '0');
      i--;
      nbr = nbr / 10;
    }
  return (buffer);
}
