#ifndef PROTOTYPES_H_
# define PROTOTYPES_H_
void	delete_char(t_line *line);
void	add_char(t_line *line);
void	x_read_line(t_line *line);
int	init_line(t_line *line);
int	get_line_caps(t_line *line);
void	go_next(t_line *line);
void	go_prev(t_line *line);
int	max_cmp(char *max, char *cmp, int max_len);
char	*get_max_str(char *max, int max_len);
char	*get_max_oc(char **oc);
void	my_sub_cat(t_edit *ed, char *old);
void	subb_char(t_edit *ed, t_shell *shell);
void	refresh_aff(t_shell *shell);
void	aff_oc(char **oc, t_edit *ed, t_shell *shell);
char	*my_strfuzf(char *str1, char *str2, int flag);
void	hist_move(t_shell *shell);
void	add_new_mem(t_shell *shell, char *line);
char	*get_cmd(t_shell *shell);
char	**epur_double(char **oc);
char	**my_tabcat(char **tab1, char **tab2);
char	**get_oc(char *path, char *str, char **oc);
char	**check_path(char **oc, t_shell *shell, char *str);
char	*my_tabul(char *str, t_shell *shell, t_edit *ed, int is_loc);
void	add_char(t_edit *ed, char add, t_shell *shell);
char	*get_cur_word(char *cmd, int of, int *is_loc);
void	get_tab_word(t_edit *ed, char *str, t_shell *shell);
char	**epur_path(char **oc, char *path);
int	my_find_double(char **tab1, char *str);
int	init_hist(t_shell *shell);
int	init_ed(t_shell *shell);
int	init_term(t_shell *shell);
void	do_key_actions(t_line *line);
int	get_term_caps(t_line *line);
int	set_termcaps(t_line *line);

#endif /* !PROTOTYPES_H_ */
