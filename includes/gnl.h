/*
** get_next_line.h for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel.chalier@epitech.eu>
** 
** Started on  Sun Apr 20 17:06:02 2014 chalie_a
** Last update Mon Apr 21 22:35:12 2014 chalie_a
*/

#ifndef GNL_H_
# define GNL_H_

# define BUFF_SIZE	1024
# define GET_LEN(a, b)	(my_strchr(0, a, 1) + my_strchr(0, b, 1) + 1)
# define END(n, s)	(n < 0 || (!n && s && !(*s)) ? 1 : 0)

#endif /* !GNL_H_ */
