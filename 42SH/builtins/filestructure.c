/*
** filestructure.c for 42sh in /home/coutar_a/rendu/42sh/42SH/builtins
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Sat May 17 17:10:24 2014 coutar_a
** Last update Sat May 17 17:59:52 2014 coutar_a
*/

#include <string.h>
#include <stdlib.h>
#include "sh.h"

char	*cd_arbor_regress(char *str)
{
  char	*ret;
  int	i;
  int	stop;

  i = 0;
  stop = strlen(str);
  while (str[stop] != '/')
    stop--;
  stop++;
  if ((ret = malloc((stop) * sizeof(char))) == NULL)
    return (NULL);
  while (i != stop)
    {
      ret[i] = str[i];
      i++;
    }
  i = i - 1;
  ret[i] = '\0';
  return (ret);
}

char	*allocstrcat(char *dest, char *src)
{
  char	*ret;
  int	l;
  int	i;
  int	j;

  i = 0;
  j = 0;
  l = strlen(dest) + strlen(src) + 1;
  if ((ret = malloc((l) * sizeof(char))) == NULL)
    return (NULL);
  ret[l - 1] = '\0';
  while (dest[i] != '\0')
    {
      ret[i] = dest[i];
      i++;
    }
  while (src[j] != '\0')
    {
      ret[i] = src[j];
      i++;
      j++;
    }
  return (ret);
}

char	*supercat(char *str1, char *str2, char *str3)
{
  char	*swap;
  char	*swap2;

  swap = allocstrcat(str1, str2);
  swap2 = allocstrcat(swap, str3);
  free(swap);
  return (swap2);
}

int	cd_chdir_error(void)
{
  printf("Error, file is not a directory.\n");
  return (-1);
}
