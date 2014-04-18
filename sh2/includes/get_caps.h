/*
** get_caps.h for sh in /home/chalie_a/rendu/PSU_2013_minishell2/includes
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:52:23 2014 chalie_a
** Last update Sun Mar  9 22:52:23 2014 chalie_a
*/

#ifndef GET_CAPS_H_
# define GET_CAPS_H_

# define UP		165
# define DOWN		166
# define LEFT		168
# define RIGHT		167
# define SPACE		32
# define ESCAPE		27
# define DEL		127
# define ENTER		10
# define MEM_POOL	1024

int	my_putchr(int);
int	clear_scr();
int	set_curs(int x, int y);
int	display_handler(int sig);
void	write_data(char **stock, int nb_row, int col_size);

#endif /* !GET_CAPS_H_ */
