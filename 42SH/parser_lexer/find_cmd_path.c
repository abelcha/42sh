/*
** find_cmd_path.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed May  7 22:20:12 2014 chalie_a
** Last update Tue May 20 13:03:50 2014 chalie_a
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include "parser.h"

#define IS_EXEC(s)	(!access(s, X_OK) && !is_dir(s) ? 1 : 0)

int			is_dir(const char* target)
{
  struct stat		statbuf;

  stat(target, &statbuf);
  return (S_ISDIR(statbuf.st_mode));
}

static char		*is_absolut_path(char *cmd)
{
  if (cmd && ((cmd[0] == '.' && cmd[1] == '/') || cmd[0] == '/')
      &&  IS_EXEC(cmd))
    return (strdup(cmd));
  return (NULL);
}

int			is_builtin(t_cmd *cmd)
{
  static char		*b_tab[6] = {"exit", "setenv", "unsetenv", "cd",
				     "env", "echo"};
  int			i;

  i = -1;
  while (++i < 6)
    if (!my_strcmp(b_tab[i], cmd->stock[0]))
      return (i);
  return (-1);
}

static char		*is_in_paths(char *cmd, t_execution *exe)
{
  int			i;
  char			*str;

  i = 0;
  while (cmd && exe->env->paths && exe->env->paths[i])
    {
      str = my_strjoint(exe->env->paths[i], cmd);
      if (IS_EXEC(str))
	return (str);
      i++;
      free(str);
    }
  return (NULL);
}

int			find_path(t_cmd *cmd, t_execution *exe)
{
  if ((cmd->builtin = is_builtin(cmd)) > 0)
    return (SUCCESS);
  if ((cmd->path = is_absolut_path(cmd->stock[0])))
    return (SUCCESS);
  if ((cmd->path = is_in_paths(cmd->stock[0], exe)))
    return (SUCCESS);
  return (FAILURE);
}
