/*
** ansi_colors.h for sh in /home/chalie_a/rendu/PSU_2013_minishell2/includes
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:52:06 2014 chalie_a
** Last update Sun Mar  9 22:52:06 2014 chalie_a
*/

#ifndef ANSI_COLOR_H_
# define ANSI_COLOR_H_

# define RED		"\033[39;31m"
# define GREEN		"\033[39;32m"
# define YELLOW		"\033[39;33m"
# define BLUE		"\033[39;34m"
# define MAGENTA	"\033[39;35m"
# define CYAN		"\033[39;36m"
# define WHITE		"\033[39;37m"
# define BOLD_RED	"\033[1;31m"
# define UNDERLINE_RED	"\033[4;31m"
# define BLINK_RED	"\033[5;31m"
# define ENDOF		"\033[0m"
# define COLOR(c, s)	triple_put(c, s, ENDOF)

#endif /* !ANSI_COLOR_H_ */
