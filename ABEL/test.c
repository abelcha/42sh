/*
** test.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Thu May  8 21:52:23 2014 chalie_a
** Last update Thu May  8 21:54:07 2014 chalie_a
*/

int	main(int ac, char **av, char **envp)
{
  envp[1][2] = '*';
  printf("%s\n", envp[1]);
}
