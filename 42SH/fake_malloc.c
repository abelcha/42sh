/*
** fake_malloc.c for Project-Master in /home/tovazm/rendu/42sh/42SH
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sat May 17 17:58:13 2014 chalie_a
** Last update Sat May 17 18:13:03 2014 chalie_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
# define M	2147483647
# define A	16807


int		my_rand (int min, int max)
{
  static int	seed;

  seed *= getpid();
  seed = A * (seed % (M / A)) - (M % A) * (seed / (M / A));
  if (seed <= 0)
    seed += M;
  return (min + seed % max);
}

extern void *calloc (size_t __nmemb, size_t __size)
{
  void	*ptr;

  if (my_rand(0, 100) == 42)
    return (NULL);
  ptr = malloc( __nmemb * __size);
  memset(ptr, 0, __nmemb * __size);
  return (ptr);
}
