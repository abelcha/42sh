/*
** my.h for my in /home/chalie_a/rendu/Piscine-C-lib/my
** 
** Made by chalie_a
** Login   <chalie_a@epitech.net>
** 
** Started on  Mon Oct 21 11:32:59 2013 chalie_a
** Last update Fri May 16 07:00:38 2014 chalie_a
*/

#include <stdlib.h>

int	my_atoi(char *str)
{
  int	res;

  if (str == NULL)
    return (0);
  if (*str == '-')
    return (-my_atoi(++str));
  if (*str == '+')
    return (my_atoi(++str));
  res = 0;
  while (*str)
    {
      if (*str > '9' || *str < '0')
	return (0);
      res = res * 10;
      res = res + *str - '0';
      ++str;
    }
  return (res);
}
