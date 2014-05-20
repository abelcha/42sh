/*
** 42sh.h for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Apr 20 23:31:35 2014 chalie_a
** Last update Tue May 20 13:33:07 2014 chalie_a
*/

#ifndef SH_H_
# define SH_H_

#include "typedefs.h"

# define LASTPIPE	(exe->nb_pipes == exe->pos + 2)
# define B_SUCCESS	0
# define B_FAILURE	2
# define TMP_FILE	".tmp"
# define ENV_BUFF	256
# define TRUNC		O_CREAT|O_TRUNC|O_WRONLY
# define READ_ONLY	O_RDONLY
# define APPEND		O_CREAT|O_APPEND|O_WRONLY
# define R_ERROR(n)	n == 1 ? -1 : 2
# define X_ERROR(...)	(fprintf(stderr, __VA_ARGS__))
# define _ERROR(...)	X_ERROR(__VA_ARGS__) ? -1 : R_ERROR(1)
# define B_ERROR(...)	X_ERROR(__VA_ARGS__) ? 2 : R_ERROR(2)

char		*gnl(const int);
int		my_strlen(char *);
int		exec_cmd(t_parse_tree *root, t_execution *);
int		my_atoi(char *);
int		my_exit(t_execution *exe, t_cmd *cmd);
int		my_env(t_execution *exe, t_cmd *cmd);
int		my_setenv(t_execution *exe, t_cmd *cmd);
int		my_unsetenv(t_execution *exe, t_cmd *cmd);
int		my_echo(t_execution *exe, t_cmd *cmd);
int		my_cd(t_execution *exe, t_cmd *cmd);
int		put_env_in_dll(char **envp, t_execution *exe);
int		put_env_in_tab(t_env *);
int		exec_builtins(t_cmd *cmd, t_execution *exe);
void		double_free(char **);
void		fill_env_struct(t_env_dll *elem, char *env_line);
int		add_env_variable(t_env_dll *elem, char *env_line);
char		*get_env_line(char *s1, char *s2);
t_env_dll	*search_for_env_variable(char *str, t_env_dll *root);
int		open_redirections(t_cmd *, t_execution *);
int		close_redirections(t_cmd *, t_execution *);
void		clear_and_display(t_line *);
int		x_free(void *ptr);
void		c_free(char **ptr);
int		add_in_history_dll(t_line *line);
int		init_history(t_line *line);
int		add_in_history(t_line *line);
int		add_in_history_file(t_line *line);
int		my_echo(t_execution *exe, t_cmd *cmd);
int		find_flags(char **stock, char *flagstatus);
int		find_strings(char **stock, char *flagstatus);
int		write_echo(char *str, char *flagstatus, const t_echo esc[]);
int		escape_code_parsing(const t_echo g_esc[], char *str, int *i);
int		byte_printer(char *str, int *i);
int		my_strcmp(char *, char *);
int		handle_redirections(t_cmd *, t_execution *);
int		is_dir(const char *);
int		my_strcmp(char *, char *);
char		**get_paths(char *, char);
int		actualise_path(t_execution *, char *);
char		*get_env(char **, char *);
t_execution	*init_exe(char **env);
t_line	 	*init_sline();
t_jobs		*init_jobs();
t_alias		*init_alias();
t_shell		*init_sh();
char		**to_tab(char *, int, char);
void		add_alias(t_shell *, char **);
int		line_realloc(t_line *);
int		parse_config_file(t_shell *);
int		clean_all(t_shell *);
char		**is_an_alias(char *, t_shell *);
char		*my_strjoint(char *s1, char *s2);
char		*my_itoa(int);
int		set_env_tech(t_execution *, char *, char *);
int		my_strlen(char *);
int		pre_parsing(t_shell *);

#endif /* !SH_H_ */
