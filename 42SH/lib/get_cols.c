/*
** get_cols.c for Project-Master in /home/tovazm/rendu/42sh/42SH
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed May 21 21:10:30 2014 chalie_a
** Last update Wed May 21 21:14:21 2014 chalie_a
*/

#include <sys/ioctl.h>
#include "edit.h"

int			get_cols()
{
  struct winsize	w;

  if (ioctl(0, TIOCGWINSZ, &w) == -1)
    return (FAILURE);
  return (w.ws_col);
}
