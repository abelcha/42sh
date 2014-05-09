/*
** x_free.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Thu May  8 16:11:57 2014 chalie_a
** Last update Sat May 10 00:36:15 2014 chalie_a
*/

#include <stdio.h>
#include <stdlib.h>

int		x_free(void *ptr)
{
  if (ptr)
    {
      free(ptr);
      ptr = NULL;
    }
  return (42);
}


void		double_free(char **ptr)
{
  int		i;

  i = -1;
  while (ptr && ptr[++i])
    x_free(ptr[i]);  
  x_free(ptr);
}
