#ifndef PROTOTYPES_H_
# define PROTOTYPES_H_
void	delete_char(t_line *line);
void	add_char(t_line *line);
void	move_back_word(t_line *line);
void	move_fwd_word(t_line *line);
void	delete_word(t_line *line);
void	x_read_line(t_line *line);
int	init_line(t_line *line);
int	get_line_caps(t_line *line);
void	move_to_start(t_line *line);
void	move_to_end(t_line *line);
void	delete_until_start(t_line *line);
void	delete_until_end(t_line *line);
void	back_to_the_future(t_line *line, char *new_line, int new_len);
void	go_next(t_line *line);
void	go_prev(t_line *line);
void	clear_scr(t_line *line);
void	do_key_actions(t_line *line);
void	clear_and_display(t_line *line);
void	replace_cursor(int oldpos, int newpos);
int	get_term_caps(t_line *line);
int	set_termcaps(t_line *line);

#endif /* !PROTOTYPES_H_ */
