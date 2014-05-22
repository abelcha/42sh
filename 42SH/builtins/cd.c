/*
** cd.c for Project-Master in /home/tovazm/rendu/42sh/42SH/builtins
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Tue May 20 10:03:48 2014 chalie_a
** Last update Thu May 22 14:00:17 2014 chalie_a
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "parser.h"
#include "sh.h"

static char		*cd_back(t_execution *exe)
{
  t_env_dll		*env_tmp;

  if ((env_tmp = search_for_env_variable("OLDPWD", exe->env->env_dll)))
    return (env_tmp->value);
  X_ERROR("Error : OLDPWD variable is not set\n");
  return (NULL);
}

static char		*cd_progressive(t_execution *exe, t_cmd *cmd)
{
  t_env_dll		*env_tmp;
  char			*tmpdir;

  if (!(env_tmp = search_for_env_variable("PWD", exe->env->env_dll)))
    {
      X_ERROR("Cant find current directory, try with an absolut path\n");
      return (NULL);
    }
  if (!(tmpdir = calloc(1, my_strlen(env_tmp->value)
			+ my_strlen(cmd->stock[1]) + 3)))
    return (NULL);
  my_strcpy(tmpdir, env_tmp->value);
  my_strcat(tmpdir, "/");
  my_strcat(tmpdir, cmd->stock[1]);
  return (tmpdir);
}

static char		*cd_home(t_execution *exe, t_cmd *cmd)
{
  t_env_dll		*env_tmp;

  printf("stock = %p\n", cmd->stock[1]);
  if ((env_tmp = search_for_env_variable("HOME", exe->env->env_dll)))
    return (!cmd->stock[1] ? env_tmp->value : 
	    my_strjoint(env_tmp->value, &(cmd->stock)[1][1]));
  X_ERROR("Error : HOME variable is not set\n");
  return (NULL);
}

char		*get_current_dir(int cpt)
{
  char		*pwd;

  if (!(pwd = calloc(cpt, _MEM_POOL)))
    return (NULL);
  if (!(getcwd(pwd, cpt * _MEM_POOL)))
    {
      free(pwd);
      return (errno == 34 ? get_current_dir(++cpt) : NULL);
    }
  return (pwd);
}

int		my_cd(t_execution *exe, t_cmd *cmd)
{
  char		*tmpdir;

  tmpdir = NULL;
  if (!cmd->stock[1] || cmd->stock[1][0] == '~')
    tmpdir = cd_home(exe, cmd);
  else if (cmd->stock[1][0] == '-' && cmd->stock[1][0])
    tmpdir = cd_back(exe);
  else if (cmd->stock[1][0] != '/')
    tmpdir = cd_progressive(exe, cmd);
  else
    tmpdir = my_strdup(cmd->stock[1]);
  return (change_dir(tmpdir, exe));
}
