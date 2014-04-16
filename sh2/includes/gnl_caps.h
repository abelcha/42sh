/*
** gnl_caps.h for sh in /home/chalie_a/rendu/PSU_2013_minishell2
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 23:03:14 2014 chalie_a
** Last update Sun Mar  9 23:03:14 2014 chalie_a
*/

#ifndef GNL_CAPS_H_
# define GNL_CAPS_H_

void	my_meminit(char **, int);
int     my_putchr(int);
int     clear_scr();
int     set_curs(int, int);
void    underline(char);
void    reverse_vid(char);
int	copy_custom(char *, const char *, short *);
void    move_cursor_right();
void    move_cursor_left();
void    move_up();
void    restore_pos();
void    cap(char *);
void    move_beg();
int     get_cols();
int     get_rows();
int     unset_termcaps();
int     set_termcaps(char **);
void	add_char_in_tab(const char, char *, const int);
void	del_char_in_tab(char *, int);
int	history_fputs(char *);
int	what_a_filling(char ***);
int	push_up(char ***, char *);
int	dl_line(int, char *);
int	clear_line(int);
int	caps_read(char **, char **);
int	pos;

#endif /* !GNL_CAPS_H_ */
