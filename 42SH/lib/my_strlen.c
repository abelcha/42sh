/*
** my_strlen.c for Project-Master in /home/tovazm/rendu/42sh/42SH
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun May 18 18:05:12 2014 chalie_a
** Last update Sun May 18 18:05:54 2014 chalie_a
*/

int		my_strlen(char *str)
{
  int		i;

  i = -1;
  if (!str)
    return (0);
  while (str[++i]);
  return (i);
}
