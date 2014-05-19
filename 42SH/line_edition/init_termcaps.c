/*
** init.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/edit_line
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon May 12 15:42:51 2014 chalie_a
** Last update Mon May 19 10:27:03 2014 chalie_a
*/

#include "edit.h"


int		get_term_caps(t_line *line)
{
  char		*term;
  if (!(term = "xterm"/*my_getenv("TERM", shell->env_keys)*/))
    return (FAILURE);
  if (tgetent(NULL, term) < 0 ||
      tcgetattr(0, &(line->sh->save)) < 0 ||
      tcgetattr(0, &(line->sh->new)) < 0)
    return (FAILURE);
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
  tcsetattr(0, TCSANOW, &(line->sh->new));
  return (SUCCESS);
}
