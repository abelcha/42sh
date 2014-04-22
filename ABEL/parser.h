/*
** parser.h for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sat Apr 19 00:10:02 2014 chalie_a
** Last update Tue Apr 22 18:14:34 2014 chalie_a
*/

#ifndef PARSER_H_
# define PARSER_H_

typedef struct		s_red
{

  int			token;
  int			fd;
  char			*name;
  struct s_red		*prev;
  struct s_red		*next;
}			t_red;

typedef struct		s_cmd
{
  int			size;
  char			*path;
  char			**stock;
  int			background;
  struct s_red		*red;
  struct s_cmd		*prev;
  struct s_cmd		*next;
}			t_cmd;

typedef struct		s_parse_tree
{
  int			token;
  struct s_cmd		*cmd;
  struct s_parse_tree	*prev;
  struct s_parse_tree	*next;
}			t_parse_tree;

#include "tokenizer.h"

#define		MEM_POOL	128
#define		BEFORE		0
#define		AFTER		1

int             lex_error(int, int, int);
int		create_new_cmd_node(t_cmd *);
int		create_new_tree_node(t_parse_tree *, t_token *);
int		add_token_in_node(t_parse_tree *, t_token *);
void   		*free_tree(t_parse_tree *);
void		display_tree(t_parse_tree *);
int		redirections(t_cmd *, t_token *);
int		expected_after_pipe();

#endif /* !PARSER_H_ */
