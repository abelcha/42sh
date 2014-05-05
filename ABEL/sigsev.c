/*
** sigsev.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Mon May  5 14:26:38 2014 chalie_a
** Last update Mon May  5 14:47:58 2014 chalie_a
*/

#include <string.h>
#include <stdlib.h>
char	*my_itoa(int nbr)
{
  char	*buffer;
  int	i;
  int	power;

  power = 10;
  i = 0;
  while ((nbr / power) > 0)
    {
      power = power * 10;
      i++;
    }
  buffer = malloc (10 * sizeof(char));
  memset(buffer, '0', 10);
  power = i;
  buffer[i + 1] = '\0';
  while (i >= 0)
    {
      buffer[i] =  (nbr - ((nbr/10) * 10) + '0');
      i--;
      nbr = nbr / 10;
    }
  return (buffer);
}

int	main(int ac, char **av)
{
  int	i;
  char	*str;

  str = calloc(1024, 1);
  i = 0;
  while (++i < 20)
    {
      strcpy(str, "sigsev ");
      strcat(str, my_itoa(i));
      printf(" str = %s\n", str);
      system(str);
    }
}
/*
int	sigg(char *av)
{
  int	pid;
  int	i;
  char	*str;
  i = -1;
      printf(",\n");
      str = malloc(1024);
      pid = getpid();
      strcpy(str, "kill -s ");
      strcat(str, av[1]);
      strcat(str, " ");
      strcat(str, my_itoa(pid));
      system(str);
      free(str);
}
*/
