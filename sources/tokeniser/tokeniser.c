/*
** main.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel.chalier@epitech.eu>
** 
** Started on  Thu Apr 17 23:43:50 2014 chalie_a
** Last update Fri May 23 12:36:52 2014 chalie_a
*/

#include <unistd.h>
#include "sh.h"

static int		fx(const char *env, const char *info, int len)
{
  int			i;

  i = 0;
  while (i < len && info[i] == env[i])
    i++;
  if (i > len - 1)
    return (SUCCESS);
  return (FAILURE);
}

char			*get_env(char **env, char *info)
{
  int			i;
  int			j;

  j = my_strlen(info);
  i = 0;
  while (env && env[i])
    {
      if (fx(env[i], info, j) == 1)
	return (&env[i][j]);
      i++;
    }
  return (NULL);
}

void			free_tokens(t_token *root)
{
  t_token		*tmp;
  t_token		*save;

  save = root->prev;
  tmp = root;
  while ((tmp = tmp->next) != root)
    XFREE(tmp->prev);
  XFREE(save);
}
