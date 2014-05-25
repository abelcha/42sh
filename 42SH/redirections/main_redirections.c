/*
** main_redirections.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel.chalier@epitech.eu>
** 
** Started on  Tue May 13 16:57:16 2014 chalie_a
** Last update Sun May 25 13:02:52 2014 chalie_a
*/

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "sh.h"

static int		open_red(t_red *red)
{
  static const int	mode[6] = {READ_ONLY, READ_ONLY, TRUNC,
				   APPEND, TRUNC, APPEND};

  if (!red)
    return (SUCCESS);
  red->fd = open(red->name, mode[red->token], 0644);
  if (red->fd < 0)
    return (ERRNO);
  red->save = dup(red->token / 2);
  if (dup2(red->fd, red->token / 2) < 0)
    return (ERRNO);
  return (SUCCESS);
}

static int		close_red(t_red *red)
{
  if (!(red) || red->fd == -1)
    return (FAILURE);
  close(red->token / 2);
  dup2(red->save, red->token / 2);
  close(red->save);
  return (SUCCESS);
}

int			handle_redirections(t_cmd *root, t_execution *exe)
{
  if (!exe->input)
    return (SUCCESS);
  if (open_red(root->next->red[0]) == FAILURE ||
      open_red(root->prev->red[1]) == FAILURE ||
      open_red(root->prev->red[2]) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}

int			close_redirections(t_cmd *root, t_execution *exe)
{
  if (!exe->input)
    return (FAILURE);
  close_red(root->next->red[0]);
  close_red(root->prev->red[1]);
  close_red(root->prev->red[2]);
  return (SUCCESS);
}
