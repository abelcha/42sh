/*
** puts.c for shell in /home/chalie_a/rendu/PSU_2013_minishell1/sources
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Wed Jan  1 03:19:12 2014 chalie_a
** Last update Sat Mar  8 19:49:24 2014 chalie_a
*/

#include <unistd.h>
#include "mysh.h"

void	my_puterr(char *str)
{
  write(STDERR_FILENO, str, my_strlen(str));
}

void	my_putstr(char *str)
{
  if (str != NULL)
    write(STDOUT_FILENO, str, my_strlen(str));
  else
    my_puterr("Cannot display a NULL string\n");
}

void	my_puts(char *str)
{
  if (str != NULL)
    write(STDOUT_FILENO, str, my_strlen(str));
  else
    my_puterr("Cannot display a NULL string\n");
  my_putchar('\n');
}

void	my_putchar(char c)
{
  write(STDOUT_FILENO, &c, 1);
}

void	my_put_nbr(int nb)
{
  int	modulo;

  modulo = 0;
  if (nb <= 9 && nb >= 0)
    my_putchar(nb + '0');
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (- 1);
      if (nb <= 9 && nb >=0)
        my_put_nbr(nb);
    }
  if (nb > 9)
    {
      modulo = nb % 10;
      my_put_nbr(nb / 10);
      my_putchar(modulo + '0');
    }
}
