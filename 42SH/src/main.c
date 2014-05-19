/*
** main.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Thu Apr 17 23:43:50 2014 chalie_a
** Last update Mon May 19 19:28:50 2014 chalie_a
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

int			main(int ac, char **av, char **env)
{
  t_token		*root;
  t_parse_tree		*tree;
  t_shell		*sh;
  int			i = 1;

  (void)av;
  (void)ac;
  if (!(sh = init_sh(env)))
    return (FAILURE);
  parse_config_file(sh);
  while (get_line_caps(sh->line) != FAILURE)
    {
      pre_parsing(sh);
      if (!(root = get_tokens(sh->line->line)))
	return (FAILURE);
      if ((tree = start_parsing(root, sh)))
	{
	  exec_cmd(tree, sh->exe);
	  free_tree(tree);
	}
      free_tokens(root);
      free(sh->line->line);
      if (sh->exe->exit || ++i > 100000)
	  break ;
    }
  add_in_history_file(sh->line);
  return (clean_all(sh));
}
