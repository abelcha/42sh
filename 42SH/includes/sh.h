/*
** 42sh.h for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Apr 20 23:31:35 2014 chalie_a
** Last update Fri May 16 03:26:29 2014 chalie_a
*/

#ifndef SH_H_
# define SH_H_

typedef struct		s_alias
{
  char			*name;
  char			*cmd;
  struct s_alias	*prev;
  struct s_alias	*next;
}			t_alias;

typedef struct		s_env_dll
{
  char			*name;
  char			*value;
  int			size;
  struct s_env_dll	*prev;
  struct s_env_dll	*next;
}			t_env_dll;

typedef struct		s_env
{
  char			**paths;
  char			**envp;
  struct s_env_dll	*env_dll;
}			t_env;

typedef struct		s_execution
{
  int			prev_pipe;
  int			*pid;
  int			fdp[2];
  int			return_value;
  int			nb_pipes;
  int			input;
  int			pos;
  int			exit;
  struct s_line		*line;
  t_env			*env;
}			t_execution;

typedef struct		s_arch
{
  char			**envp;
  char			*prompt;
  t_alias		*alias;
  t_execution		*exe;
}			t_arch;

typedef struct		s_echo
{
  char			second;
  char			code;
}			t_echo;

#include "parser.h"
#include "edit.h"

typedef int	(*ptrft)(t_execution *exe, t_cmd *cmd);

char		*gnl(const int);
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
int		write_echo(char *str, char *flagstatus, t_echo *esc);
int		escape_code_parsing(t_echo *g_esc, char *str, int *i);
int		byte_printer(char *str, int *i);
int		my_strcmp(char *, char *);
int		handle_redirections(t_cmd *, t_execution *);

# define TMP_FILE	".tmp"
# define ENV_BUFF	4096
# define TRUNC		O_CREAT|O_TRUNC|O_WRONLY
# define READ_ONLY	O_RDONLY
# define APPEND		O_CREAT|O_APPEND|O_WRONLY
# define _ERROR(...)	fprintf(stderr, __VA_ARGS__) ? -1 : FAILURE
# define B_ERROR(...)	fprintf(stderr, __VA_ARGS__) ? B_FAILURE : B_FAILURE
#endif /* !SH_H_ */
