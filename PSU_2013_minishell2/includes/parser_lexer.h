/*
** mysh.h for mysh in /home/chalie_a/rendu/PSU_2013_minishell1
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sat Dec 28 05:43:11 2013 chalie_a
** Last update Sat Mar  8 21:16:03 2014 chalie_a
*/

#ifndef PARSER_LEXER_H_
# define PARSER_LEXER_H_

typedef struct s_list
{
  char	****command;
  char	*file_name[2];
  int	in_red;
  int	out_red;
  int	err_red;
}t_dll;

int	type;

#endif /* !PARSER_LEXER_H_ */
