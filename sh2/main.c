/*
** main.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:43:42 2014 chalie_a
** Last update Wed Mar 12 16:38:36 2014 
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include "mysh.h"
#include "x_error.h"
#include "parser_lexer.h"


int		count_pipes(char ***command)
{
  int		i;

  i = -1;
  while (command[++i]);
  return (i);
}

int		jackie_minishell(char **env)
{
  t_dll		*list;
  int		x = -1;
  char		**paths;
  int		*saves;

  saves = NULL;
  paths = PATHS;
  if ((list = command_parsing(get_lucky(env), env, paths)))
    {
      if ((saves = red_action(list)))
      while (list->command[++x])
	exec_pipe(list->command[x], count_pipes(list->command[x]), paths, env);
      close_all(saves);
      quad_free(list->command);
      x_free(list);
    }
  double_free(paths);
  return (force_exit != FALSE ? force_exit : jackie_minishell(env));
}
