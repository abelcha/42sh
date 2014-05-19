/*
** pre_parsing.c for Project-Master in /home/tovazm/rendu/42sh/42SH
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon May 19 17:25:33 2014 chalie_a
** Last update Mon May 19 17:33:14 2014 chalie_a
*/

#include "sh.h"
#include "parser.h"

int		parse_line(char *str, t_shell *sh)
{
  char		**tmp;

  if (!(tmp = is_an_alias(str, sh)))
    
}

int		pre_parsing(t_shell *sh)
{
  char		**stock;

  if (!(stock = to_tab(sh->line, 0, ' ')))
    return (FAILURE);
  while (stock[++i])
    parse_line(stock[i], sh);
}
