/*
** termc.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/termcaps
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:47:49 2014 chalie_a
** Last update Sun Mar  9 22:47:49 2014 chalie_a
*/

#include <sys/ioctl.h>
#include <termios.h>
#include <stdlib.h>
#include <term.h>
#include <curses.h>
#include "my.h"
#include "x_error.h"
#include "get_caps.h"

static char		*get_from_env(char *str, char **env)
{
  int			j;
  char			*ret;

  if (env == NULL)
    return (NULL);
  j = 0;
  while (env[j] && my_strncmp(str, env[j], my_strlen(str)) != 0)
    j++;
  if (env[j] == NULL)
    return (NULL);
  ret = &(env[j][my_strlen(str)]);
  return (ret);
}

int			unset_termcaps()
{
  struct termios	term;

  if (tputs(tgetstr("vs", NULL), 0, my_putchr) == -1)
    return (FAILURE);
  if (tcgetattr(0, &term) == -1)
    return (-1);
  term.c_lflag += ECHO;
  term.c_lflag += ICANON;
  term.c_cc[VMIN] = 1;
  if (tcsetattr(0, TCSANOW, &term) == -1)
    return (ERROR(UNSETCAPS_FAIL));
  return (SUCCESS);
}

int			set_termcaps(char **env)
{
  struct termios	term;
  char			*tmp;

  if (tcgetattr(0, &term) == -1)
    return (FAILURE);
  term.c_lflag = term.c_lflag & ~ICANON;
  term.c_lflag = term.c_lflag & ~ECHO;
  term.c_cc[VMIN] = 1;
  if (tcsetattr(0, TCSANOW, &term) == -1)
    return (ERROR(SETCAPS_FAIL));
  tmp = get_from_env("TERM=", env);
  if (tmp == NULL || tgetent(NULL, tmp) != 1)
    return (ERROR(GET_ENV));
  return (SUCCESS);
}
