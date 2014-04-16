/*
** my_x.c for my_x in /home/chalie_a/BSQ
** 
** Made by chalie_a
** Login   <chalie_a@epitech.net>
** 
** Started on  Sun Dec  8 17:24:24 2013 chalie_a
** Last update Thu Mar 27 23:50:06 2014 chalie_a
*/
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "mysh.h"

int		x_open(const char *str)
{
  int		fd;

  if (str && (fd = open(str, (O_RDWR | O_CREAT | O_APPEND), 0777)) != -1)
    close(fd);
  else
    return (FAILURE);
  return (SUCCESS);
}

void		*x_calloc(int size, int of)
{
  char		*temp;

  if ((temp = malloc((size * of) + 4)) == NULL)
    {
      my_putstr("Error : Malloc Failed");
      return (NULL);
    }
  my_memset(temp, 0, size * of);
  return (temp);
}

void		*x_malloc(int size)
{
  char		*temp;

  if ((temp = malloc(size + 4)) == NULL)
    {
      my_putstr("Error : Malloc Failed");
      exit(EXIT_FAILURE);
    }
  my_memset(temp, 0, size);
  return (temp);
}

int		x_free(void *ptr)
{
  if (ptr != NULL)
    free(ptr);
  ptr = NULL;
  return (54);
}
