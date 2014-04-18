/*
** tokenizer.h for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Fri Apr 18 00:51:03 2014 chalie_a
** Last update Fri Apr 18 06:30:58 2014 chalie_a
*/

#ifndef TOKENIZER_H_
# define TOKENIZER_H_

typedef struct		s_token
{
  char			*data;
  int			data_size;
  int			token;  
  struct s_token	*prev;
  struct s_token	*next;
}			t_token;

#define SPACE   ' '
#define TAB     '\t'
#define FALSE   -1
#define TRUE    1
#define SUCCESS	1
#define FAILURE	-1

#define IS_ESCAPED(i, str)      i == 0 || str[i - 1] != '\\' ? FALSE : TRUE
#define IS_SEP(c)		(c != SPACE && c != TAB) ? FALSE : TRUE
#define TOKEN_MATCH(s1, s2)	s1[0] == s2[0] && (s1[1] == s2[1] || s1[1] == 0) ? TRUE : FALSE


#define T_CHAR "><|&;"
#define T_CHAR_NBR 5

#define T_RED_CC 0
#define T_RED_C  1
#define T_RED_DD 2
#define T_RED_D  3
#define T_OR	 4
#define T_PIPE	 5
#define T_AND	 6
#define T_SEM	 7
#define T_CMD	 8
#define T_EOL	 9
#endif /* !TOKENIZER_H_ */
