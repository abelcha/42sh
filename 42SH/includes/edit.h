/*
** edit.h for Project-Master in /home/tovazm/rendu/42sh/ABEL/edit_line
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon May 12 15:12:30 2014 chalie_a
** Last update Sat May 17 17:54:01 2014 chalie_a
*/

#ifndef EDIT_H_
# define EDIT_H_

/*
** Ctrl-a	Move to the start of the line.
** Ctrl-e	Move to the end of the line.
** Ctrl-b	Move back one character.
** Alt-b	Move back one word.
** Ctrl-f	Move forward one character.
** Alt-f	Move forward one word.
** Ctrl-u	Delete from the cursor to the beginning of the line.
** Ctrl-k	Delete from the cursor to the end of the line.
** Ctrl-w	Delete from the cursor to the start of the word.
** Ctrl-l	Clear the screen
*/

# define AK_NB		18
# define K_LEFT		4479771
# define K_RIGHT	4414235
# define K_DEL		127
# define K_UP		4283163
# define K_DOWN		4348699
# define K_TAB		9
# define K_RET		10
# define CTRL_A		1
# define CTRL_E		5		
# define CTRL_B		2
# define ALT_B		25115
# define CTRL_F		6
# define ALT_F		26139
# define CTRL_E		5
# define CTRL_U		21
# define CTRL_K		11
# define CTRL_W		23
# define CTRL_L		12
# define ALT_I		26907
# define CTRL_D		4
# define BUFF_LINE	4096
# define ARG		12
# define CMD		42

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <term.h>
# include <sys/ioctl.h>
# include <string.h>
# include <fcntl.h>

typedef struct		s_history
{
  int			len;
  char			*data;
  struct s_history	*prev;
  struct s_history	*next;
}			t_history;

typedef struct		s_glob
{
  int			len;
  char			*data;
  struct s_glob		*prev;
  struct s_glob		*next;
}			t_glob;

typedef struct		s_gb
{
  t_glob		*g;
  char			*word;
  int			word_len;
  int			total;
  int			part_match;
}			t_gb;


typedef struct		s_line
{
  int			pos;
  int			line_len;
  int			key;
  char			*prompt;
  int			pre_prompt;
  int			p_size;
  char			*line;
  char			*line_save;
  int			tab_flag;
  struct s_execution	*exe;
  struct s_history	*curr_pos;
  struct s_history	*history;
  struct termios	save;
  struct termios	new;
}			t_line;

/*
**     For Signals Only
**		|
**		v
*/

extern t_line		*lx;

typedef			void(*t_ak)(t_line *line);

#define VALID_CHAR(c)	(c > 31 && c < 127 ? 1 : 0)
#define SUCCESS		1
#define FAILURE		-1
#define CAP(s)		tgetstr(s, NULL) ? W_CAP(tgetstr(s, NULL)) : 0
#define W_CAP(s)	write(1, s, strlen(s))

void	delete_char(t_line *line);
void	add_char(t_line *line);
int	x_read_line(t_line *line);
int	init_line(t_line *line);
int	get_line_caps(t_line *line);
void	go_next(t_line *line);
void	go_prev(t_line *line);
void	do_key_actions(t_line *line);
int	get_term_caps(t_line *line);
int	set_termcaps(t_line *line);
char	*gnl(int);
int	signal_ctz(int);
void	tab_glob(t_line *line);
void	move_to_start(t_line *line);
void	move_to_end(t_line *line);
void	delete_until_start(t_line *line);
void	delete_until_end(t_line *line);
void	move_fwd_char(t_line *line);
void	move_back_word(t_line *line);
void	move_fwd_word(t_line *line);
void	delete_word(t_line *line);
void	clear_and_display(t_line *line);
void	replace_cursor(int oldpos, int newpos);

#endif /* !EDIT_H_ */
