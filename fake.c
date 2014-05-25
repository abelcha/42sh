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

extern void	*calloc(size_t __nmemb, size_t __size)
{
  void		*ptr;
  static int	i =0;

  if (my_rand(0, 100) == 42)
    return (NULL);
  ptr = malloc( __nmemb * __size);
  memset(ptr, 0, __nmemb * __size);
  return (ptr);
}
