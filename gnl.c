/*
** gnl.c for Project-Master in /home/tovazm/rendu/42sh
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sat Apr 19 19:34:27 2014 chalie_a
** Last update Sat Apr 19 19:42:45 2014 chalie_a
*/

#define BUFF_SIZE 1024
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
char	*gnl(int fd)
{
  static int	nb_read = BUFF_SIZE;
  char	*buffer;
  int	flag;

  if (nb_read < BUFF_SIZE)
    return (NULL);
  buffer = calloc(BUFF_SIZE + 4, sizeof(char));
  nb_read = read(STDIN_FILENO, buffer, BUFF_SIZE);
  return (buffer);
}

int	main()
{
  char *str;
  while (str = gnl(0))
    printf("%s\n", str);
}
