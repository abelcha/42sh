/*
** find_cmd_path.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Wed May  7 22:20:12 2014 chalie_a
** Last update Thu May  8 11:54:32 2014 chalie_a
*/


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include "tokenizer.h"
#include "parser.h"
#include "sh.h"

#define IS_EXEC(s)	(!access(s, X_OK) && !is_dir(s) ? 1 : 0)

int		is_dir(const char* target)
{
  struct	stat statbuf;

  stat(target, &statbuf);
  return (S_ISDIR(statbuf.st_mode));
}

char			*my_strcat(char *s1, char *s2)
{
  char			*new;
  int			i;
  int			j;
  int			len;

  i = 0;
  j = 0;
  len = strlen(s1) + strlen(s2);
  new = malloc((len + 1) * sizeof(char));
  memset(new, '\0', len + 1);
  while (s1[i])
    {
      new[i] = s1[i];
      i++;
    }
  while (s2[j])
    {
      new[i + j] = s2[j];
      j++;
    }
  return (new);
}

static char		*is_absolut_path(char *cmd)
{
  if (((cmd[0] == '.' && cmd[1] == '/') || cmd[0] == '/')
      &&  IS_EXEC(cmd))
    return (strdup(cmd));
  return (NULL);
}

static char		*is_in_paths(char *cmd, t_execution *exe)
{
  int			i;
  char			*str;

  i = 0;
  while (exe->paths && exe->paths[i])
    {
      str = my_strcat(exe->paths[i], cmd);
      if (IS_EXEC(str))
	return (str);
      i++;
      free(str);
    }
  return (NULL);
}

int			find_path(t_cmd *cmd, t_execution *exe)
{
  if ((cmd->path = is_absolut_path(cmd->stock[0])) && printf("is lol\n"))
    return (SUCCESS);
  if ((cmd->path = is_in_paths(cmd->stock[0], exe)))
    return (SUCCESS);
  return (SUCCESS);
}
