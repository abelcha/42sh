/*
** parser.h for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sat Apr 19 00:10:02 2014 chalie_a
** Last update Thu May 15 04:16:24 2014 chalie_a
*/

#ifndef PARSER_H_
# define PARSER_H_

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

# include "tokenizer.h"
# include "sh.h"
# define MEM_POOL	128
# define BEFORE		0
# define AFTER		1
#  define SIMPLE_RED__	O_CREAT|O_TRUNC|O_WRONLY
# define __SIMPLE_RED	O_RDONLY
# define DOUBLE_RED__	O_CREAT|O_APPEND|O_WRONLY 

int		main(int, char **, char **);
int		speed_cmp(char *, char *);
void		free_tokens(t_token *);
char		**get_paths(char *, char);
char		*get_env(char **, char *);
void		free_token(t_token *);
int		x_free(void *);
int		execution_loop(t_cmd *, t_execution *);
int		find_path(t_cmd *, t_execution *exe);
int             lex_error(int, int, int);
int		create_new_cmd_node(t_cmd *);
int		create_new_tree_node(t_parse_tree *, t_token *);
int		add_token_in_node(t_parse_tree *, t_token *, t_execution *exe);
void   		*free_tree(t_parse_tree *);
void		display_tree(t_parse_tree *);
int		redirections(t_cmd *, t_token *, t_execution *);
int		expected_after_pipe();
#endif /* !PARSER_H_ */
