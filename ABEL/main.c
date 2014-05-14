/*
** main.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Thu Apr 17 23:43:50 2014 chalie_a
** Last update Mon May 12 23:44:23 2014 chalie_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "edit.h"
#include "sh.h"
#include "parser.h"
#include "my_color.h"
#include "tokenizer.h"

#define PROMPT		1, "\033[39;31m>\033[0m", 13

t_execution		*init_exe(char **env)
{
  t_execution		*exe;

  if (!(exe = calloc(1, sizeof(t_execution))))
    return (NULL);
  if (!(exe->env = calloc(1, sizeof(t_env))))
    return (NULL);
  if (put_env_in_dll(env, exe) == FAILURE)
    return (NULL);
  if (!(exe->env->paths = get_paths(get_env(env, "PATH="), ':')))
    return (NULL);
  return (exe);
}

static void		free_exe(t_env_dll *root)
{
  t_env_dll		*tmp;
  t_env_dll		*save;

  if (!root)
    return ;
  save = root->prev;
  tmp = root;
  while ((tmp = tmp->next) != root)
    x_free(tmp->prev);
  x_free(save);
}

int			clean_all(t_execution *exe)
{
  int			i;
  int			exit_value;

  i = -1;
  exit_value = exe->exit;
  free_exe(exe->env->env_dll);
  double_free(exe->env->paths);
  double_free(exe->env->envp);
  free(exe->env);
  free(exe);
  return (exit_value);
}

void			init_prompt(t_line *line)
{
  line->prompt = "\033[39;31mAbel>$\033[0m";
  line->p_size = strlen(line->prompt);
}

int			main(int ac, char **av, char **env)
{
  t_token		*root;
  t_parse_tree		*tree;
  t_execution		*exe;
  t_line		*line;
  int			i = 1;

  av = NULL;
  ac = 0;
  if (!(exe = init_exe(env)))
    return (FAILURE);
  if (!(line = calloc(1, sizeof(t_line))))
    return (FAILURE);
  if (init_history(line) == FAILURE)
    return (FAILURE);
  init_prompt(line);
  while (get_line_caps(line) != FAILURE)
    {
      root = get_tokens(line->line);
      if ((tree = start_parsing(root, exe)))
	{
	  exec_cmd(tree, exe);
	  free_tree(tree);
	}
      free_tokens(root);
      if (exe->exit || ++i > 10000)
	break ;
    }
  add_in_history_file(line);
  return (clean_all(exe));
}
