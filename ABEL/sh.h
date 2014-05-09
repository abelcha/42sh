/*
** 42sh.h for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Apr 20 23:31:35 2014 chalie_a
** Last update Fri May  9 00:53:26 2014 chalie_a
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
  int			pos;
  int			exit;
  t_env			*env;
}			t_execution;

typedef struct		s_arch
{
  char			**envp;
  char			*prompt;
  t_alias		*alias;
  t_execution		*exe;
}			t_arch;

#include "parser.h"

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


# define ENV_BUFF	4096
# define _ERROR(...)    fprintf(stderr, __VA_ARGS__) ? -1 : FAILURE

#endif /* !SH_H_ */
