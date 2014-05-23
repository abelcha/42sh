/*
** init.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/edit_line
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon May 12 15:42:51 2014 chalie_a
** Last update Fri May 23 19:42:19 2014 chalie_a
*/

#include <unistd.h>
#include <signal.h>
#include <stdlib.h> 
#include "sh.h"
#include "edit.h"

t_line			*lx;

int			line_realloc(t_line *line)
{
  line->line = realloc(line->line, ++(line->realloc_cpt) * BUFF_LINE + 4);
  if (line->line)
    return (SUCCESS);
  return (FAILURE);
}

static int		x_read_line(t_line *line)
{
  line->tab_flag = 0;
  while (line->key != K_RET && line->line)
    {
      line->key = 0;
      if (read(0, &(line->key), 4) <= 0 || line->key == CTRL_D)
	{
	  tcsetattr(0, TCSANOW, &(line->sh->save));
	  line->line = NULL;
	  return (FAILURE);
	}
      do_key_actions(line);
      if (line->pos >= (BUFF_LINE * line->realloc_cpt))
	line_realloc(line);
   }
  return (SUCCESS);
}

static int		init_line(t_line *line)
{
  line->sh->curr_pos = NULL;
  line->line_len = 0;
  line->key = 0;
  line->pos = 0;
  line->realloc_cpt = 1;
  if (!(line->line = calloc(BUFF_LINE + 4, sizeof(char))))
    return (FAILURE);
  return (SUCCESS);
}

int			get_line_caps(t_line *line)
{
  lx = line;
  if (!isatty(0) || set_termcaps(line) == FAILURE)
      line->line = gnl(0);
  else if (init_line(line) == SUCCESS)
    {
      signal(SIGINT, (__sighandler_t) signal_ctz);
      write(1, line->sh->prompt, line->sh->p_size);
      if (x_read_line(line) == FAILURE)
	return (FAILURE);
      if (line->line != line->line_save)
	XFREE(line->line_save);
      if (line && my_strlen(line->line))
	add_in_history_dll(line);
      tcsetattr(0, TCSANOW, &(line->sh->save));
      write(1, "\n", 1);
    }
  else
    return (FAILURE);
  return (line->line ? SUCCESS : FAILURE);
}
