/*
** redir.c for redir in /home/chalie_a/rendu/sh2
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Feb  2 02:27:50 2014 chalie_a
** Last update Sat Mar  8 20:30:20 2014 chalie_a
*/

#include <unistd.h>
#include "mysh.h"

int	y_or_n(char *str)
{
  char	buffer[256];

  my_putstr(str);
  my_putstr(" [Y/n]\n");
  read(0, buffer, 256);
  if (buffer[0] == 'y' || buffer[0] == 'Y')
    return (YES);
  else if (buffer[0] == 'N' || buffer[0] == 'n')
    return (NO);
  else
    {
      my_putstr("It is not a valid option\n");
      return (y_or_n(str));
    }
}
