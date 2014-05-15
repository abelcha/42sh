/*
** x_error.c for xerroe in /home/chalie_a/PSU_2013_my_select/lib
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Mon Jan 13 07:21:37 2014 chalie_a
** Last update Sun Mar  9 18:57:10 2014 chalie_a
*/

#include <unistd.h>
#include "x_error.h"
#include "mysh.h"

int	my_strlen(char *str);

void	write_err(char *str)
{
  write(STDERR_FILENO, "Error : ", 8);
  write(STDERR_FILENO, str, my_strlen(str));
}
int	put_error(char *str)
{
  write_err(str);
  return (FAILURE);
}

void	*put_null_error(char *str)
{
  write_err(str);
  return (NULL);
}

int	unset_error(int flag, char *str)
{
  if (flag == 1)
    my_putstr("error, too few argument.\n");
  if (flag == 2)
    my_putstr("error, too much argument.\n");
  else if (flag == 3)
    {
      my_putstr("cannot unset `");
      if (my_strlen(str))
        my_putstr(str);
      my_putstr("`, no such variable environement\n");
      return (FAILURE);
    }
  my_putstr("Usage : unsetenv <variable name>\n");
  return (FAILURE);
}

void	arg_error(char *str)
{
  int	i;

  i = -1;
  write(STDERR_FILENO, "Error : ", 8);
  while (str[++i] && str[i] != ' ')
    write(STDERR_FILENO, &str[i], 1);
  write(STDERR_FILENO, " Command Not Found\n", 21);
}
