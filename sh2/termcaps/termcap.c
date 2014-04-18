/*
** termcap.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/termcaps
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:48:03 2014 chalie_a
** Last update Sun Mar  9 22:48:03 2014 chalie_a
*/

#include <term.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include "x_error.h"
#include "my.h"
#include "get_caps.h"

int		my_putchr(int c)
{
  return (write(STDOUT_FILENO, &c, 1));
}

void		reverse_vid(char c)
{
  tputs(tgetstr("mr", NULL), 0, my_putchr);
  my_putchar(c);
  tputs(tgetstr("me", NULL), 0, my_putchr);
}

void		move_cursor_left()
{
  tputs(tgetstr("le", NULL), 0, my_putchr);
}

void		cap(char *str)
{
  tputs(tgetstr(str, NULL), 0, my_putchr);
}
