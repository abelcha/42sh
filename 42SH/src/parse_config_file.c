/*
** parse_config_file.c for Project-Master in /home/tovazm/rendu/42sh/42SH
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon May 19 12:03:53 2014 chalie_a
** Last update Fri May 23 11:14:59 2014 chalie_a
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "sh.h"
#include "parser.h"

int		read_config_file(t_shell *sh)
{
  int		fd;
  char		*s;

  if ((fd = open("./.42rc", (O_RDWR | O_CREAT | O_APPEND), 0777)) < 0)
    return (FAILURE);
  while ((s = gnl(fd)))
    add_info(sh, s);
  return (SUCCESS);
}

int		parse_config_file(t_shell *sh)
{
  sh->hist_limit = 1000;
  sh->prompt = "\033[39;31m42sh>$\033[0m";
  sh->p_size = my_strlen(sh->prompt);
  sh->p_valid = 6;
  if (read_config_file(sh) == FAILURE)
    return (_ERROR("Error : Invalid Config File\n\n"));
  check_double_alias(sh->alias);
  return (SUCCESS);
}
