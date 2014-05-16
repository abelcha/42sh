/*
** signal.c for Project-Master in /home/tovazm/rendu/42sh/42SH
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Thu May 15 20:08:37 2014 chalie_a
** Last update Thu May 15 20:28:26 2014 chalie_a
*/

#include "edit.h"

int		signal_ctz(int sig)
{
  int		i;

  if (!isatty(0))
    return (0);
  i = -2;
  lx->line_len = 0;
  lx->key = 0;
  lx->pos = 0;
  lx->line[0] = 0;
  write(1, "^C", 2);
  while (++i < (lx->p_size))
    CAP("le");
  printf("\n");
  write(1, lx->prompt, lx->p_size);
  clear_and_display(lx);
  return (sig);
}
