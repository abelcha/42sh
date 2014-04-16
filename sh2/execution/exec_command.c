/*
** exec_command.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/execution
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:41:02 2014 chalie_a
** Last update Sun Mar  9 22:41:02 2014 chalie_a
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include "mysh.h"
#include "x_error.h"

int	x_execve(char **stock, char **env, char *str, char **path)
{
  cast(path);
  if (execve(str, stock, env) == -1)
    exit(FAILURE);
  x_free(str);
  return (SUCCESS);
}

int	find_exec_path(char **path, char **stock, char **env)
{
  int	i;
  char	*str;

  i = 0;
  if (access(stock[0], X_OK) == 0)
    return (x_execve(stock, env, my_strdup(stock[0]), path));
  while (path[i])
    {
      str = my_strcat(path[i], stock[0]);
     if (access(str, X_OK) == 0)
       return (x_execve(stock, env, str, path));
     else
       i++;
     x_free(str);
    }
  my_putstr(stock[0]);
  my_putstr(" : command not found\n");
  return (FAILURE);
}

int	exec_command(char **path, char **stock, char **env)
{
  find_exec_path(path, stock, env);
  return (SUCCESS);
}
