/*
** main.c for Project-Master in /home/tovazm/rendu/42sh
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed Apr 16 03:26:08 2014 chalie_a
** Last update Wed Apr 16 03:26:44 2014 chalie_a
*/

t_ballot			*init_root()
{
  t_champ		*root;

  if (!(init = malloc(sizeof(t_ballot))))
    return (NULL);
  init->prev = root;
  init->next = root;
  return (init);
}
