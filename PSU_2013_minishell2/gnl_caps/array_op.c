/*
** array_op.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:56:13 2014 chalie_a
** Last update Sun Mar  9 22:56:13 2014 chalie_a
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "mysh.h"
#include "gnl_caps.h"

void	add_char_in_tab(const char c, char *str, const int pos)
{
  int	i;

  if (pos < 0)
    return ;
  i = strlen(str);
  while (i >= pos)
    {
      str[i + 1] = str[i];
      --i;
    }
  str[pos] = c;
}

void	del_char_in_tab(char *str, int pos)
{
  int	i;

  i = my_strlen(str);
  while (pos < i)
    {
      str[pos] = str[pos + 1];
      ++pos;
    }
}

int		history_fputs(char *bh)
{
  int		fd;
  const char	c = '\n';

  if (my_strlen(bh) < 2)
    return (FAILURE);
  fd = open("/tmp/.sh_history", O_CREAT | O_APPEND | O_WRONLY);
  if (bh && fd != -1)
    {
      write(fd, bh, my_strlen(bh));
      write(fd, &c, 1);
      close(fd);
    }
  return (SUCCESS);
}

int		what_a_filling(char ***buff_history)
{
  int		i;
  int		fd;
  char		*str;

  i = -1;
  fd = open("/tmp/.sh_history", O_RDONLY);
  if (fd == -1)
    return (FAILURE);
  while ((str = gnl(fd)) && i < BUFF_SIZE)
    (*buff_history)[++i] = str;
  return (SUCCESS);
}

int		push_up(char ***stock, char *str)
{
  int		i;

  i = 0;
  if (str[0] == '\0')
    return (0);
  while ((*stock)[i])
    ++i;
  if ((*stock)[0] && !(my_strncmp((*stock)[0], str, i)))
    return (0);
  while (i >= 0)
    {
      (*stock)[i + 1] = (*stock)[i];
      --i;
    }
  (*stock)[0] = my_strdup(str);
  return (SUCCESS);
}
