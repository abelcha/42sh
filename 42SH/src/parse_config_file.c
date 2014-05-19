/*
** parse_config_file.c for Project-Master in /home/tovazm/rendu/42sh/42SH
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon May 19 12:03:53 2014 chalie_a
** Last update Mon May 19 14:05:02 2014 chalie_a
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "parser.h"

int		get_valid_len(char *str)
{
  int		i;
  int		j;

  j = 0;
  i = -1;
  while (str[++i])
    if (str[i] > 20 && str[i] < 127)
      ++j;
  return (j);
}

void			hist_limit(t_shell *sh, char **stock)
{
  int			tmp;

  if (!stock)
    return ;
  if ((tmp = my_atoi(stock[1])))
    sh->hist_limit = tmp;
}

void			hist_ignore(t_shell *sh, char **stock)
{
  if (!stock || !stock[1])
    return ;
  sh->hist_ign = to_tab(stock[1], 0, ':');
}


void			add_info(t_shell *sh, char *str)
{
  static char		*conf_tab[3] = {"HIST_LIMIT", "HIST_IGNORE", "ALIAS"};
  static const t_conf	conf_fct[3] = {hist_limit, hist_ignore, add_alias};
  int			i;
  char			**stock;

  i = -1;
  if (!(stock = to_tab(str, 0, ' ')))
    return ;
  while (++i != 3)
    if (!my_strcmp(stock[0], conf_tab[i]))
      conf_fct[i](sh, stock);
  free(str);
}

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
  sh->p_valid = get_valid_len(sh->prompt);
  if (read_config_file(sh) == FAILURE)
    return (_ERROR("Error : Invalid Config File\n\n"));
  return (SUCCESS);
}
