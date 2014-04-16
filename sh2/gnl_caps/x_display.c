/*
** x_display.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 23:04:11 2014 chalie_a
** Last update Sun Mar  9 23:04:11 2014 chalie_a
*/

#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "x_error.h"
#include "mysh.h"
#include "get_caps.h"
#include "ansi_colors.h"
#include "gnl_caps.h"

int		copy_custom(char *dest, const char *src, short *len)
{
  short		i;

  i = -1;
  while (src[++i])
    dest[i] = src[i];
  *len = i;
  pos = i;
  dest[i] = ' ';
  dest[i + 1] = 0;
  return (SUCCESS);
}

int		clear_line(int start)
{
  while (++start < 42)
    write(1, " ", 1);
  return (SUCCESS);
}

int		dl_line(const int pos, char *buffer)
{
  short		i;

  i = 0;
  cap("sc");
  move_cursor_left();
  i = -1;
  while (++i < pos)
    write(1, &(buffer[i]), 1);
  reverse_vid(buffer[i]);
  while (buffer[i++])
    write(1, &(buffer[i]), 1);
  clear_line(i);
  cap("rc");
  return (RUNNING);
}
