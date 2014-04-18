/*
** close_red.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/redirections
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:51:03 2014 chalie_a
** Last update Sun Mar  9 22:51:03 2014 chalie_a
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "x_error.h"
#include "mysh.h"

static int	close_red(int output, int save)
{
  close(output);
  if (dup2(save, output) < 0)
    return (ERROR(DUP_FAIL));
  close(save);
  return (SUCCESS);
}

int		close_all(int *saves)
{
  int		i;

  i = -1;
  while (++i < 3)
    if (saves[i] != -1)
      close_red(i, saves[i]);
  if (saves)
    free(saves);
  return (SUCCESS);
}
