/*
** edit.h for Project-Master in /home/tovazm/rendu/42sh/ABEL/edit_line
** 
** Made by chalie_a
** Login   <abel.chalier@epitech.eu>
** 
** Started on  Mon May 12 15:12:30 2014 chalie_a
** Last update Sun May 25 20:48:44 2014 chalie_a
*/

#ifndef EDIT_H_
# define EDIT_H_

# include "typedefs.h"

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
# define BUFF_LINE	256
# define ARG		12
# define CMD		42

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
#define CAP(s)		cap(s)

void	cap(char *);
void	delete_char(t_line *line);
void	add_char(t_line *line);
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
void    move_left(t_line *line);
void	move_right(t_line *line);
void	clear_scr(t_line *line);
void	real_tab(t_line *line);
void	delete_word(t_line *line);
void	clear_and_display(t_line *line);
void	replace_cursor(int oldpos, int newpos);
int	get_cols();
void	display_pos(t_gb *root, t_line *line);
void	tab_glob(t_line *line);
int	get_command(char *word, t_line *line, t_gb *gb);
int	get_type(const char *, int);
char	*get_word(char *, int, int *);

#endif /* !EDIT_H_ */
