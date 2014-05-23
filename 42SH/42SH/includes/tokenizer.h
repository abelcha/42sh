/*
** tokenizer.h for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Fri Apr 18 00:51:03 2014 chalie_a
** Last update Fri May 23 12:29:13 2014 chalie_a
*/

#ifndef TOKENIZER_H_
# define TOKENIZER_H_

# include "typedefs.h"

# define SPACE		' '
# define TAB		'\t'
# define FALSE		-1
# define TRUE		1
# define SUCCESS	1
# define FAILURE	-1
# define IS_ESCAPED(i, str)	i == 0 || str[i - 1] != '\\' ? FALSE : TRUE
# define IS_SEP(c)		(c != SPACE && c != TAB) ? FALSE : TRUE
# define TOKEN_MATCH(s, d)	*s == *d && (s[1] == d[1] || !(s[1])) ? 1 : -1
# define IS_MAJOR(c)		(c == 4 || c == 6 || c == 3 || c == 13 ? 1 : 0)
# define LLG(c)			((c == 5 || c == 6 || c == 4) ? 1 : 0)
# define T_CHAR			"><|&`;"
# define T_CHAR_NBR		6
# define T_AMP_R		0
# define T_BACK			1
# define T_R_AMP		2
# define T_SEM			3
# define T_OR			4
# define T_PIPE			5
# define T_AND			6
# define T_AMP			7
# define T_RED_DD		8
# define T_RED_D		9
# define T_RED_CC		10
# define T_RED_C		11
# define T_CMD			12
# define T_EOL			13
# define T_NBR			14
# define IN_RED(c)		(c == T_RED_C || c == T_RED_CC) ? 1 : 0
# define OUT_RED(c)		(c == 9 || c == 8 || c == 0 || c == 2) ? 1 : 0

t_parse_tree	*start_parsing(t_token *, t_shell *sh);
int		add_token_in_list(t_token *, int);
t_token		*get_tokens(char *);

#endif /* !TOKENIZER_H_ */
