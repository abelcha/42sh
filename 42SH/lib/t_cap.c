/*
** t_cap.c for Project-Master in /home/tovazm/rendu/42sh/42SH
** 
** Made by chalie_a
** Login   <abel.chalier@epitech.eu>
** 
** Started on  Wed May 21 21:20:58 2014 chalie_a
** Last update Wed May 21 21:28:07 2014 chalie_a
*/

#include <unistd.h>
#include <term.h>
#include <stdlib.h>
#include "sh.h"

void		cap(char *s)
{
  char		*tmp;

  if (!s || !(tmp = tgetstr(s, NULL)))
    return ;
  write(1, tmp, my_strlen(tmp));
}
