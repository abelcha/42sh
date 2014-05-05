/*
** get_next_line.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Apr 20 17:05:51 2014 chalie_a
** Last update Wed Apr 23 11:56:43 2014 chalie_a
*/

#include <unistd.h>
#include <stdlib.h>
#include "gnl.h"

static void		*x_free(void *ptr)
{
  if (ptr)
    {
      free(ptr);
      ptr = NULL;
    }
  return (NULL);
}

static int		copy_data(const char *tmp, char *str)
{
  int			j;

  j = -1;
  if (!tmp)
    return (0);
  while (tmp[++j])
    str[j] = tmp[j];
  return (j);
}

static int		my_strchr(const char c, const char *str, const int flag)
{
  int			i;

  i = -1;
  if (!str)
    return (flag - 1);
  while (str[++i] || flag)
    if (str[i] == c)
      return (i);
  return (-1);
}

static char		*reinit_all(char *tmp, const int nb, char *buffer)
{
  char			*str;
  int			i;
  int			j;

  i = 0;
  str = calloc(GET_LEN(tmp, buffer), sizeof(char));
  if (!str)
    return (x_free(tmp));
  j = tmp ? copy_data(tmp, str) : 0;
  x_free(tmp);
  while (buffer[i] && i < nb)
    str[j++] = buffer[i++];
  return (str);
}

char			*gnl(const int fd)
{
  static char		buffer[BUFF_SIZE];
  static int		nb;
  char			*str;
  int			j;

  str = !(*buffer) ? NULL : reinit_all(0, nb, buffer);
  while ((j = my_strchr('\n', str, 0)) == -1)
    if ((nb = read(fd, buffer, BUFF_SIZE)) <= 0)
      return (END(nb, str) ? x_free(str) : str);
    else if ((str = reinit_all(str, nb, buffer)) == 0)
      return (x_free(str));
  nb = 0;
  while (str[++j])
    buffer[nb++] = str[j];
  return ((str[j - nb - 1] = 0) ? NULL : str);
}

/*
int		main()
{
  char		*str;
  int		i = -1;
  while ((str = gnl(0)))
    {
       printf("%s\n", str);
       free(str);
       if (++i > 10000)
	 break;
    }
  //  free(str);
}

*/
