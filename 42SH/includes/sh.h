/*
** 42sh.h for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Apr 20 23:31:35 2014 chalie_a
** Last update Sun May 18 08:36:05 2014 chalie_a
*/

#ifndef SH_H_
# define SH_H_

#include "typedefs.h"

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
int		cd_home(t_execution *exe, t_cmd *cmd);
int		cd_other(t_execution *exe, t_cmd *cmd, int check);
int		cd_home(t_execution *exe, t_cmd *cmd);
int		cd_progressive(t_execution *exe, t_cmd *cmd);
int		cd_absolute(t_execution *exe, t_cmd *cmd);
int		cd_regressive(t_execution *exe, t_cmd *cmd);
int		cd_other(t_execution *exe, t_cmd *cmd, int check);
char		*cd_arbor_regress(char *str);
char		*allocstrcat(char *dest, char *src);
char		*supercat(char *str1, char *str2, char *str3);
int		cd_chdir_error(void);
int		is_dir(const char *);
int		my_strcmp(char *, char *);
char		**get_paths(char *, char);
int		actualise_path(t_execution *, char *);
char		*get_env(char **, char *);
# define LASTPIPE	(exe->nb_pipes == exe->pos + 2) 
# define B_SUCCESS	0
# define B_FAILURE	2
# define TMP_FILE	".tmp"
# define ENV_BUFF	4096
# define TRUNC		O_CREAT|O_TRUNC|O_WRONLY
# define READ_ONLY	O_RDONLY
# define APPEND		O_CREAT|O_APPEND|O_WRONLY
# define _ERROR(...)	fprintf(stderr, __VA_ARGS__) ? -1 : FAILURE
# define B_ERROR(...)	fprintf(stderr, __VA_ARGS__) ? B_FAILURE : B_FAILURE

#endif /* !SH_H_ */
