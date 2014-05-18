/*
** main.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Thu Apr 17 23:43:50 2014 chalie_a
** Last update Sun May 18 17:39:50 2014 chalie_a
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
  exe->input = isatty(0);
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
  line->prompt = "\033[39;31m42sh>$\033[0m";
  line->p_size = strlen(line->prompt);
}

t_line 			*init_sline()
{
  t_line		*line;

  if (!(line = calloc(1, sizeof(t_line))))
    return (NULL);
  if (init_history(line) == FAILURE)
    return (NULL);
  init_prompt(line);
  return (line);
}

void			link_all_structs(t_execution *exe, t_line *line)
{
  exe->line = line;
  line->exe = exe;
}

int			main(int ac, char **av, char **env)
{
  t_token		*root;
  t_parse_tree		*tree;
  t_execution		*exe;
  t_line		*line;
  int			i = 1;

  (void)av;
  (void)ac;
  if (!(line = init_sline()) || !(exe = init_exe(env)))
    return (FAILURE);
  link_all_structs(exe, line);
  while (get_line_caps(line) != FAILURE)
    {
      if (!(root = get_tokens(line->line)))
	return (FAILURE);
      if ((tree = start_parsing(root, exe)))
	{
	  exec_cmd(tree, exe);
	  free_tree(tree);
	}
      free_tokens(root);
      free(line->line);
      if (exe->exit || ++i > 100000)
	  break ;
    }
  add_in_history_file(line);
  return (clean_all(exe));
}
