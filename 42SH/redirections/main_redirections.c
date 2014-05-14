/*
** main_redirections.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Tue May 13 16:57:16 2014 chalie_a
** Last update Wed May 14 21:12:42 2014 chalie_a
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "sh.h"
#include "parser.h"

/* UGLY FUNTION */

void		fill_red(t_red *red)
{
  if (red->token == T_RED_D || red->token == T_RED_DD)
    red->output = STDOUT_FILENO;
  else if (red->token == T_RED_C || red->token == T_RED_CC)
    {
      red->mode = __SIMPLE_RED;
      red->output = STDIN_FILENO;
    }
  else if (red->token == T_AMP_R || red->token == T_R_AMP)
    red->output = STDERR_FILENO;

  if (red->token == T_RED_D)
    red->mode = SIMPLE_RED__;
  if (red->token == T_RED_DD)
    red->mode = DOUBLE_RED__;
}
/* UGLY FUNTION A REFAIRE*/

static int	open_red(t_red *red)
{
  // fill_red(red);
  printf("yoloswa\n");
  red->save = dup(STDOUT_FILENO);
  red->fd = open(red->name, SIMPLE_RED__, 0644);
  if (red->fd < 0)
    return (FAILURE);
  if (dup2(red->fd, STDOUT_FILENO) < 0)
    return (FAILURE);
  return (SUCCESS);
}
int		close_red(t_red *red)
{
  close(red->output);
  dup2(red->save, red->output);
  close(red->save);
  return (SUCCESS);
}

