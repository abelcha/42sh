/*
** main.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Thu Apr 17 23:43:50 2014 chalie_a
** Last update Tue May  6 15:34:01 2014 chalie_a
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "sh.h"
#include "parser.h"
#include "tokenizer.h"

#define PROMPT		1, "\033[39;31m>\033[0m", 13

char			**paths;
char			**envp;
char			**get_paths(char *, char);

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

int			main(int ac, char **av, char **env)
{
  t_token		*root;
  t_parse_tree		*tree;
  char			*str;
  int			i = 1;

  envp = env;
  paths = get_paths(get_env(env, "PATH="), ':');

  while (write(PROMPT) && (str = gnl(0)))
    {
      root = get_tokens(str);
      if ((tree = start_parsing(root)))
	free_tree(tree);
      free(str);
      free_tokens(root);
      if (++i > 10000)
	{
	  i = -1;
	  while (paths[++i])
	    free(paths[i]);
	  free(paths);
	  return (0);
	}
    }
}
