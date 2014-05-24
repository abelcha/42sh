/*
** main.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel.chalier@epitech.eu>
** 
** Started on  Thu Apr 17 23:43:50 2014 chalie_a
** Last update Sat May 24 18:11:48 2014 chalie_a
*/

#include "edit.h"
#include "sh.h"
#include "parser.h"
#include "tokenizer.h"

int			main(int ac, char **av, char **env)
{
  t_token		*root;
  t_parse_tree		*tree;
  t_shell		*sh;

  (void)av;
  (void)ac;
  if (!(sh = init_sh(env)))
    return (FAILURE);
  parse_config_file(sh);
  while (!sh->exe->exit && get_line_caps(sh->line) != FAILURE)
    {
      pre_parsing(sh);
      if (!(root = get_tokens(sh->line->line)))
	return (FAILURE);
      if ((tree = start_parsing(root, sh)) && (sh->exe->return_value = 2))
	{
	  exec_cmd(tree, sh->exe);
	  free_tree(tree);
	}
      free_tokens(root);
      XFREE(sh->line->line);
    }
  add_in_history_file(sh->line);
  return (clean_all(sh));
}
