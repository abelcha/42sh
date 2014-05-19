/*
** edit.h for Project-Master in /home/tovazm/rendu/42sh/ABEL/edit_line
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon May 12 15:12:30 2014 chalie_a
** Last update Mon May 19 18:48:11 2014 beau_v
*/

#ifndef EDIT_H_
# define EDIT_H_

# include "typedefs.h"

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
# define BUFF_LINE	256
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
int	get_command(char *word, t_line *line, t_gb *gb);
int	get_cols();
int	bigger_len(t_glob *root);
void	write_and_blanks(int maxlen, int len, char *str);
int	yes_or_no(int total);
void	print_list(int maxlen, t_glob *root, int cols);
void	display_pos(t_gb *root, t_line *line);
int	get_partial_matching(char *s1, char *s2);
int	is_doublon(char *str, t_glob *root);
int	add_glob(t_gb *root, char *data, int len);
t_glob	*init_glob();
void	remplace_it(t_line *line, t_gb *gb, int start);
void	free_glob_list(t_gb *gb);
void	tab_glob(t_line *line);
int	get_type(char *line, int pos);
char	*get_word(char *line, int pos, int *type);
char	*get_fusion(char *path, char *word, int *len);
void	check_match(char *temp, t_gb *gb, int len);
int	get_data(char *path, char *word, t_gb *gb);
int	get_command(char *word, t_line *line, t_gb *gb);

#endif /* !EDIT_H_ */
