/*
** init.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/edit_line
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon May 12 15:42:51 2014 chalie_a
** Last update Sat May 17 03:55:03 2014 chalie_a
*/

#include "sh.h"
#include "edit.h"

t_line			*lx;

void			x_read_line(t_line *line)
{
  line->tab_flag = 0;
  while (line->key != K_RET)
    {
      line->key = 0;
      if (read(0, &(line->key), 4) < 0 && line->line)
	{
	  line->line = NULL;
	  return ;
	}
      do_key_actions(line);
   }
}

int			init_line(t_line *line)
{
  int			i;

  i = -2;
  CAP("dl");
  while (++i < (line->p_size - line->pre_prompt))
    CAP("le");
  line->curr_pos = NULL;
  line->line_len = 0;
  line->key = 0;
  line->pos = 0;
  if (!(line->line = calloc(BUFF_LINE, sizeof(char))))
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
      write(1, line->prompt, line->p_size);
      x_read_line(line);
      if (line->line != line->line_save)
	c_free(&(line->line_save));
      if (line && strlen(line->line))
	add_in_history_dll(line);
      tcsetattr(0, TCSANOW, &(line->save));
    }
  else
    return (FAILURE);
  write(1, "\n", 1);
  if (line->line)
    return(SUCCESS);
  return (line->line ? SUCCESS : FAILURE);
}
