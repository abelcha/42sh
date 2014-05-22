/*
** init.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/edit_line
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon May 12 15:42:51 2014 chalie_a
** Last update Wed May 21 22:22:59 2014 chalie_a
*/

#include <string.h>
#include <stdio.h>
#include <term.h>
#include <errno.h>
#include "edit.h"
#include "sh.h"

int		get_term_caps(t_line *line)
{
  char		*term;

  if (!(term = get_env(line->sh->exe->env->envp, "TERM=")))
    term = "xterm";
  if (tgetent(NULL, term) < 0 ||
      tcgetattr(0, &(line->sh->save)) < 0 ||
      tcgetattr(0, &(line->sh->new)) < 0)
    return (ERRNO);
  return (SUCCESS);
}

int		set_termcaps(t_line *line)
{
  static char	init = 0;

  if (++init == 1)
    {
      if (get_term_caps(line) == FAILURE)
	return (FAILURE);
      line->sh->new.c_lflag &= ~(ICANON | ECHO);
    }
  if (tcsetattr(0, TCSANOW, &(line->sh->new)) == FAILURE)
    return (ERRNO);
  return (SUCCESS);
}
