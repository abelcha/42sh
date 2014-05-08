/*
** isdir.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed May  7 22:08:52 2014 chalie_a
** Last update Wed May  7 22:11:32 2014 chalie_a
*/

#include <sys/stat.h>

int	is_dir(const char* target)
{
  struct stat statbuf;

  stat(target, &statbuf);
  return (S_ISDIR(statbuf.st_mode));
}

int		main(int ac, char **av)
{
  is_dir(av[1]);
}
