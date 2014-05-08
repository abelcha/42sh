/*
** main.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Thu Apr 17 23:43:50 2014 chalie_a
** Last update Thu May  8 13:44:09 2014 chalie_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "sh.h"
#include "parser.h"
#include "my_color.h"
#include "tokenizer.h"

#define PROMPT		1, "\033[39;31m>\033[0m", 13

char			**get_paths(char *, char);

int			main(int ac, char **av, char **env)
{
  t_token		*root;
  t_parse_tree		*tree;
  t_execution		*exe;
  char			*str;
  int			i = 1;

  g_exit = 0;
  if (!(exe = calloc(1, sizeof(t_execution))))
    return (FAILURE);
  exe->envp = env;
  exe->paths = get_paths(get_env(env, "PATH="), ':');
  while (write(PROMPT) && (str = gnl(0)))
    {
      root = get_tokens(str);
      if ((tree = start_parsing(root, exe)))
	{
	  exec_cmd(tree, exe);
	  free_tree(tree);
	}
      free(str);
      free_tokens(root);
      if (g_exit || ++i > 10000)
	{
	  i = -1;
	  while (exe->paths[++i])
	    free(exe->paths[i]);
	  free(exe->paths);
	  free(exe);
	  return (0);
	}
    }
}
