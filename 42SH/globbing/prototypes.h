#ifndef PROTOTYPES_H_
# define PROTOTYPES_H_
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

#endif /* !PROTOTYPES_H_ */
