/*
** strmatch.c for Project-Master in /home/tovazm/rendu/lem-in
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed Apr 16 23:57:38 2014 chalie_a
** Last update Fri May  2 09:19:59 2014 chalie_a
*/

#include <stdio.h>

int		speed_cmp(char *s, char *s2)
{
  return (*s == *s2 ? !(*s) ? 0 : speed_cmp(++(s), ++(s2)) : 1);
}

int		my_strcmp(char *s1, char *s2)
{
  return (!s1 && !s2 ? 0 : !s1 || !s2 ? 1 : speed_cmp(s1, s2));
}
