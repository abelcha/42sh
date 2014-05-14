/*
** x_read.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:57:26 2014 chalie_a
** Last update Sun Mar  9 22:57:26 2014 chalie_a
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "x_error.h"
#include "my.h"
#include "mysh.h"
#include "get_caps.h"
#include "ansi_colors.h"
#include "gnl_caps.h"

static int	key_read()
{
  char		buff[5];

  if (read(1, buff, 3) <= 0)
    return (FAILURE);
  if (buff[0] == 27 && buff[1] == 91)
    return (100 + buff[2]);
  else
    return (*buff);
}

static int	key_code(short key, short *len, char *buffer,
			 char **buff_history)
{
  static int	i = -1;
  static char	*save = NULL;

  if (key == 42)
    {
      free(save);
      save = NULL;
      i = -1;
      return (SUCCESS);
    }
  if (i == -1 && !(i = 0))
    save = my_strdup(buffer);
  if (key == RIGHT && pos < *len && pos++);
  else if (key == LEFT && pos > 0 && pos--);
  else if (key == UP && buff_history[i])
    copy_custom(buffer, buff_history[i++], len);
  else if (key == DOWN)
    {
      if (i > 0 && i--)
	copy_custom(buffer, buff_history[i], len);
      else
	copy_custom(buffer, save, len);
    }
  return (SUCCESS);
}

static int	crossroad(char *buffer, char **buff_history)
{
  short		key;
  static short	len = 0;

  if ((key = key_read()) == FAILURE || len > BUFF_SIZE - 3)
    return (FAILURE);
  if (key > 150)
    key_code(key, &len, buffer, buff_history);
  else if (key == DEL && pos > 0 && len > 0)
    {
      del_char_in_tab(buffer, --pos);
      len--;
    }
  else if (key == ENTER && !(pos = 0))
    {
      buffer[len] = '\0';
      dl_line(len + 1, buffer);
      my_putchar('\n');
      len = 0;
      key_code(42, NULL, NULL, NULL);
      return (SUCCESS);
    }
  else if (key > 30 && key < 127 && ++pos && ++len)
    add_char_in_tab(key, buffer, pos - 1);
  buffer[len] = ' ';
  return (dl_line(pos, buffer));
}

int		caps_read(char **buffer, char **buff_history)
{
  short		status;

  cap("vi");
  my_memset(*buffer, '\0', BUFF_SIZE);
  reverse_vid(' ');
  while ((status = crossroad(*buffer, buff_history)) != SUCCESS)
    {
      if (status == FAILURE)
	return (FAILURE);
    }
  return (SUCCESS);
}
