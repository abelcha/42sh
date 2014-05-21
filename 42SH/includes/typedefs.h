/*
** typedefs.h for Project-Master in /home/tovazm/rendu/42sh/42SH/includes
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun May 18 06:57:23 2014 chalie_a
** Last update Tue May 20 18:24:19 2014 chalie_a
*/

#ifndef TYPEDEFS_H_
# define TYPEDEFS_H_

#include <termios.h>


typedef struct		s_red
{
  int			token;
  int			fd;
  int			save;
  char			*name;
  struct s_red		*prev;
  struct s_red		*next;
}			t_red;

typedef struct		s_cmd
{
  int			size;
  char			*path;
  char			**stock;
  int			builtin;
  int			background;
  int			realloc_cpt;
  struct s_red		*red[3];
  struct s_cmd		*prev;
  struct s_cmd		*next;
}			t_cmd;

typedef struct		s_parse_tree
{
  int			token;
  int			nb_pipes;
  struct s_cmd		*cmd;
  struct s_parse_tree	*prev;
  struct s_parse_tree	*next;
}			t_parse_tree;

typedef struct		s_token
{
  char			*data;
  int			data_size;
  int			token;
  struct s_token	*prev;
  struct s_token	*next;
}			t_token;

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
  int			total_nb;
  int			realloc_cpt;
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
  int			curr_pid;
  int			pos;
  int			exit;
  struct s_shell	*sh;
  struct s_env		*env;
}			t_execution;

typedef struct		s_echo
{
  char			second;
  char			code;
}			t_echo;


typedef struct		s_history
{
  int			len;
  char			*data;
  struct s_history	*prev;
  struct s_history	*next;
}			t_history;

typedef struct		s_glob
{
  int			len;
  char			*data;
  struct s_glob		*prev;
  struct s_glob		*next;
}			t_glob;

typedef struct		s_gb
{
  t_glob		*g;
  char			*word;
  int			word_len;
  int			total;
  int			part_match;
}			t_gb;


typedef struct		s_line
{
  int			pos;
  int			line_len;
  int			key;
  char			*line;
  char			*line_save;
  int			realloc_cpt;
  int			tab_flag;
  struct s_shell	*sh;

}			t_line;

typedef struct		s_alias
{
  char			*name;
  char			**cmd;
  struct s_alias	*prev;
  struct s_alias	*next;
}			t_alias;

typedef struct		s_jobs
{
  char			*cmd;
  int			nbr;
  int			pid;
  struct s_jobs		*prev;
  struct s_jobs		*next;
}			t_jobs;


typedef struct		s_shell
{
  char			*prompt;
  int			p_size;
  int			p_valid;
  int			hist_limit;
  char			**hist_ign;
  struct s_jobs		*jobs;
  struct s_line		*line;
  struct s_alias	*alias;
  struct s_execution	*exe;
  struct s_history	*curr_pos;
  struct s_history	*history;
  struct termios	save;
  struct termios	new;
}			t_shell;

typedef void	(*t_conf)(t_shell *sh, char **stock);
typedef int	(*ptrft)(t_execution *exe, t_cmd *cmd);

#endif /* !TYPEDEFS_H_ */
