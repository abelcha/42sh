/*
** my_memset.c for Project-Master in /home/tovazm/rendu/42sh/42SH
** 
** Made by chalie_a
** Login   <abel.chalier@epitech.eu>
** 
** Started on  Wed May 21 22:24:04 2014 chalie_a
** Last update Wed May 21 22:24:36 2014 chalie_a
*/

void		*my_memset(void *data, char value, int size)
{
  int		i;

  i = -1;
  while (++i < size)
    ((char *)data)[i] = value;
  return (data);
}
