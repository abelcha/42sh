/*
** signal.c for Project-Master in /home/tovazm/rendu/42sh/42SH
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Thu May 15 20:08:37 2014 chalie_a
** Last update Mon May 19 12:11:38 2014 chalie_a
*/

#include "edit.h"
#include "sh.h"
void		kill_sons(int *pid)
{
  int		x;

  x = -1;
  while (pid[++x])
    {
      printf("pid = %d\n", pid[x]);
      kill(pid[x], 9);
    }
}

int		signal_ctz(int sig)
{
  int		i;

  if (!isatty(0))
    return (0);
  if (lx->sh->exe->pid)
    kill_sons(lx->sh->exe->pid);
  i = -2;
  lx->line_len = 0;
  lx->key = 0;
  lx->pos = 0;
  lx->line[0] = 0;
  write(1, "^C", 2);
  while (++i < (lx->sh->p_size))
    CAP("le");
  printf("\n");
  write(1, lx->sh->prompt, lx->sh->p_size);
  clear_and_display(lx);
  return (sig);
}
