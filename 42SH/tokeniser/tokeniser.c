/*
** main.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Thu Apr 17 23:43:50 2014 chalie_a
** Last update Tue May 20 14:56:01 2014 chalie_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "sh.h"
#include "parser.h"
#include "my_color.h"
#include "tokenizer.h"

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

  j = strlen(info);
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
    free(tmp->prev);
  free(save);
}
