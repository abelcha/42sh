/*
** main_redirections.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Tue May 13 16:57:16 2014 chalie_a
** Last update Fri May 16 02:01:54 2014 chalie_a
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "sh.h"
#include "parser.h"

extern int		is_atty;

static int		open_red(t_red *red)
{
  static const int	mode[6] = {READ_ONLY, READ_ONLY, TRUNC,
				   APPEND, TRUNC, APPEND};

  if (!red)
    return (SUCCESS);
  red->fd = open(red->name, mode[red->token], 0644);
  if (red->fd < 0)
    return (_ERROR("Error : Cannot open `%s'\n", red->name));
  red->save = dup(red->token / 2);
  if (dup2(red->fd, red->token / 2) < 0)
    return (_ERROR("Error : Dup Failed\n"));
  return (SUCCESS);
}

int		close_red(t_red *red)
{
  if (!(red) || red->fd == -1)
    return (FAILURE);
  close(red->token / 2);
  dup2(red->save, red->token / 2);
  close(red->save);
  return (SUCCESS);
}

int		handle_redirections(t_cmd *root, t_execution *exe)
{
  if (!exe->input)
    return (FAILURE);
  open_red(root->next->red[0]);
  open_red(root->prev->red[1]);
  open_red(root->prev->red[2]);
  return (SUCCESS);
}

int		close_redirections(t_cmd *root, t_execution *exe)
{
  if (!exe->input)
    return (FAILURE);
  close_red(root->next->red[0]);
  close_red(root->prev->red[1]);
  close_red(root->prev->red[2]);
  return (SUCCESS);
}
