/*
** edit.h for Project-Master in /home/tovazm/rendu/42sh/ABEL/edit_line
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon May 12 15:12:30 2014 chalie_a
** Last update Tue May 13 01:30:54 2014 chalie_a
*/

#ifndef EDIT_H_
# define EDIT_H_

# define K_UP		4283163
# define K_DOWN		4348699
# define K_LEFT		4479771
# define K_RIGHT	4414235
# define K_TAB		9
# define K_RET		10
# define K_DEL		127
# define BUFF_LINE	4096
#include <stdio.h>

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <term.h>
#include <sys/ioctl.h>
#include <string.h>
#include <fcntl.h>                    

typedef struct		s_history
{
  int			len;
  char			*data;
  struct s_history	*prev;
  struct s_history	*next;
}			t_history;


typedef struct		s_line
{
  int			pos;
  int			line_len;
  int			key;
  char			*prompt;
  int			p_size;
  char			*line;
  char			*line_save;
  struct s_history	*curr_pos;
  struct s_history	*history;
  struct termios	save;
  struct termios	new;
}			t_line;

typedef			void(*t_ak)(t_line *line);

#define VALID_CHAR(c)	(c > 31 && c < 127 ? 1 : 0)
#define AK_NB		5
#define SUCCESS		1
#define FAILURE		-1
#define CAP(s)		tgetstr(s, NULL) ? W_CAP(tgetstr(s, NULL)) : 0
#define W_CAP(s)	write(1, s, strlen(s))

void	delete_char(t_line *line);
void	add_char(t_line *line);
void	x_read_line(t_line *line);
int	init_line(t_line *line);
int	get_line_caps(t_line *line);
void	go_next(t_line *line);
void	go_prev(t_line *line);
void	do_key_actions(t_line *line);
int	get_term_caps(t_line *line);
int	set_termcaps(t_line *line);
char	*gnl(int);

#endif /* !EDIT_H_ */
