/*
** echo.c for 42sh in /home/coutar_a/Projets/42sh/42sh/sh2/buildins
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Mon May  5 09:50:58 2014 coutar_a
** Last update Thu May 22 12:01:17 2014 chalie_a
*/

#include <string.h>
#include "sh.h"

static int		find_flags(char **stock, char *flagstatus)
{
  int			i;

  i = -1;
  while (stock[++i] != NULL)
    {
      if ((my_strcmp(stock[i], "-n")) == 0)
	flagstatus[0] = 1;
      if ((my_strcmp(stock[i], "-e")) == 0)
	flagstatus[1] = 1;
      if ((my_strcmp(stock[i], "-E")) == 0)
	flagstatus[1] = 0;
    }
  return (0);
}

int			my_echo(t_execution *exe, t_cmd *cmd)
{
  char			flagstatus[2];

  (void)exe;
  flagstatus[0] = 0;
  flagstatus[1] = 0;
  find_flags(cmd->stock, flagstatus);
  find_strings(cmd->stock, flagstatus);
  return (B_SUCCESS);
}
