/*
** 42sh.h for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Apr 20 23:31:35 2014 chalie_a
** Last update Fri Apr 25 22:29:52 2014 chalie_a
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

typedef struct		s_exe
{
  int			pid;
  int			*fdp;
  int			nb_pipes;
  int			pos;
}			t_exe;

typedef struct		s_arch
{
  char			**env;
  char			*prompt;
  t_alias		*alias;
  t_exe			*exe;
}			t_arch;


char		*gnl(const int);

#endif /* !SH_H_ */
