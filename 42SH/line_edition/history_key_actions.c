/*
** history_key_actions.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/edit_line
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon May 12 20:49:22 2014 chalie_a
** Last update Sun May 18 15:46:21 2014 chalie_a
*/

#include <termios.h>
#include "edit.h"
#include "sh.h"

void		safecpy(char *dest, char *str)
{
  int		i;

  i = -1;
  while (str[++i] && i < BUFF_LINE)
    dest[i] = str[i];
  dest[i] = 0;
}


void		back_to_the_future(t_line *line, char *new_line, int new_len)
{
  if (strlen(new_line) < BUFF_LINE)
    strcpy(line->line, new_line);
  replace_cursor(line->pos, new_len);
  line->pos = new_len;
  line->line_len = new_len;
  clear_and_display(line);
}

void		go_next(t_line *line)
{
  if (!line->curr_pos || line->curr_pos == line->history)
    return ;
  if (line->curr_pos->next == line->history)
    back_to_the_future(line, line->line_save, strlen(line->line_save));
  else
    back_to_the_future(line, line->curr_pos->next->data, line->curr_pos->next->len);
  line->curr_pos = line->curr_pos->next;
}


void		go_prev(t_line *line)
{
  if (!line->curr_pos)
    {
      if (!(line->line_save = calloc(BUFF_LINE, sizeof(char))))
	return ;
      line->curr_pos = line->history;
      strcpy(line->line_save, line->line);
      // if (!(line->line = calloc(BUFF_LINE, sizeof(char))))		WHY THE FUCK DID I'VE DONE THAT ??
      //	return ;
    }
  if (line->curr_pos->prev == line->history)
    return ;
  line->curr_pos = line->curr_pos->prev;
  back_to_the_future(line, line->curr_pos->data, line->curr_pos->len);
}
