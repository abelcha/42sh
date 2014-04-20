/*
** parser.h for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sat Apr 19 00:10:02 2014 chalie_a
** Last update Sun Apr 20 14:12:22 2014 chalie_a
*/

#ifndef PARSER_H_
# define PARSER_H_

typedef struct		s_red
{

  int			token;
  int			fd;
  char			*file;
  struct s_red		*prev;
  struct s_red		*next;
}			t_redirections;


typedef struct		s_cmd
{
  int			size;
  char			*path;
  char			**stock;
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



#endif /* !PARSER_H_ */
