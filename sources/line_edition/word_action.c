/*
** word_action.c for Project-Master in /home/tovazm/rendu/42sh/ABEL/line_edition
** 
** Made by chalie_a
** Login   <abel.chalier@epitech.eu>
** 
** Started on  Wed May 14 06:45:56 2014 chalie_a
** Last update Wed May 14 20:09:52 2014 chalie_a
*/

#include "edit.h"

void		move_back_word(t_line *line)
{
  while (line->pos > 0 && (line->line[line->pos - 1] == ' ' ||
			   line->line[line->pos - 1] == '\t'))
    {
      --line->pos;
      CAP("le");
    }
  while (line->pos > 0 && (line->line[line->pos - 1] != ' ' &&
			   line->line[line->pos - 1] != '\t'))
    {
      --(line->pos);
      CAP("le");
    }
}

void		move_fwd_word(t_line *line)
{
  while (line->pos < line->line_len && (line->line[line->pos + 1] != ' ' &&
					line->line[line->pos + 1] != '\t'))
    {
      ++(line->pos);
      CAP("nd");
    }
  while (line->pos < line->line_len && (line->line[line->pos + 1] == ' ' ||
					line->line[line->pos + 1] == '\t'))
    {
      ++line->pos;
      CAP("nd");
    }
}

void		delete_word(t_line *line)
{
  while (line->pos > 0 && (line->line[line->pos - 1] == ' ' ||
			   line->line[line->pos - 1] == '\t'))
    {
      --line->pos;
      line->line[line->pos] = 0;
      CAP("le");
    }
  while (line->pos > 0 && (line->line[line->pos - 1] != ' ' &&
			   line->line[line->pos - 1] != '\t'))
    {
      --(line->pos);
      line->line[line->pos] = 0;
      CAP("le");
    }
  line->line_len = line->pos;
  clear_and_display(line);
}

