/*
** 42sh.h for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Apr 20 23:31:35 2014 chalie_a
** Last update Thu May  8 13:37:18 2014 chalie_a
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

typedef struct		s_execution
{
  int			prev_pipe;
  int			*pid;
  int			fdp[2];
  int			return_value;
  int			nb_pipes;
  int			pos;
  char			**paths;
  char			**envp;
}			t_execution;

typedef struct		s_arch
{
  char			**envp;
  char			*prompt;
  t_alias		*alias;
  t_execution		*exe;
}			t_arch;

#include "parser.h"

char		*gnl(const int);
int		exec_cmd(t_parse_tree *root, t_execution *);
# define _ERROR(...)    fprintf(stderr, __VA_ARGS__) ? -1 : FAILURE
#endif /* !SH_H_ */
