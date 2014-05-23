/*
** x_free.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Thu May  8 16:11:57 2014 chalie_a
** Last update Thu May 22 23:45:40 2014 chalie_a
*/

#include <stdio.h>
#include <stdlib.h>

int		safe_free(void **ptr)
{
  if (*ptr)
    {
      free(*ptr);
      *ptr = NULL;
    }
  return (42);
}

int		x_free(void *ptr)
{
  if (ptr)
    {
      free(ptr);
      ptr = NULL;
    }
  return (42);
}

void		double_free(char ***ptr)
{
  int		i;

  i = -1;
  while ((*ptr) && (*ptr)[++i])
    if ((*ptr)[i])
      {
	free((*ptr)[i]);
	(*ptr)[i] = NULL;
      }
  if (*ptr)
    {      
      free(*ptr);
      ptr = NULL;
    }
}
