/*
** my_itoa.c for shell in /home/chalie_a/rendu/PSU_2013_minishell1/sources
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sat Dec 28 05:45:26 2013 chalie_a
** Last update Sat Dec 28 05:45:26 2013 chalie_a
*/

#include "../includes/mysh.h"

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
  buffer = x_malloc (10 * sizeof(char));
  my_memset(buffer, '0', 10);
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
