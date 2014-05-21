/*
** cd.c for Project-Master in /home/tovazm/rendu/42sh/42SH/builtins
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Tue May 20 10:03:48 2014 chalie_a
** Last update Tue May 20 13:31:10 2014 chalie_a
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "parser.h"
#include "sh.h"

int		change_dir(char *newdir)
{
  if ((access(newdir, F_OK | R_OK)) == -1)
    return (B_ERROR("%s\n", strerror(errno)));
  if (chdir(newdir) == FAILURE)
    return (B_ERROR("%s\n", strerror(errno)));
  return (B_SUCCESS);
}

char		*cd_back(t_execution *exe)
{
  t_env_dll	*env_tmp;

  if ((env_tmp = search_for_env_variable("OLDPWD", exe->env->env_dll)))
    return (env_tmp->value);
  X_ERROR("Error : OLDPWD variable is not set\n");
  return (NULL);
}

char		*cd_progressive(t_execution *exe, t_cmd *cmd)
{
  t_env_dll	*env_tmp;
  char		*tmpdir;

  if (!(env_tmp = search_for_env_variable("PWD", exe->env->env_dll)))
    {
      X_ERROR("Cant find current directory, try with an absolut path\n");
      return (NULL);
    }
  if (!(tmpdir = calloc(1, strlen(env_tmp->value)
			+ strlen(cmd->stock[1]) + 3)))
    return (NULL);
  strcpy(tmpdir, env_tmp->value);
  strcat(tmpdir, "/");
  strcat(tmpdir, cmd->stock[1]);
  return (tmpdir);
}

char		*cd_home(t_execution *exe)
{
  t_env_dll	*env_tmp;

  if ((env_tmp = search_for_env_variable("HOME", exe->env->env_dll)))
    return (env_tmp->value);
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

int		actualise_pwd(t_execution *exe)
{
  char		*new_pwd;
  t_env_dll	*tmp;

  if (!(new_pwd = calloc(1, 1024)))
    return (B_FAILURE);
  if ((tmp = search_for_env_variable("PWD", exe->env->env_dll)))
    set_env_tech(exe, "OLDPWD", tmp->value);
  if (!(new_pwd = get_current_dir(1)))
    return (B_FAILURE);
  set_env_tech(exe, "PWD", new_pwd);
  return (B_SUCCESS);
}

int		my_cd(t_execution *exe, t_cmd *cmd)
{
  char		*tmpdir;

  tmpdir = NULL;
  if (!cmd->stock[1] || cmd->stock[1][0] == '~')
    tmpdir = cd_home(exe);
  else if (cmd->stock[1][0] == '-' && cmd->stock[1][0])
    tmpdir = cd_back(exe);
  else if (cmd->stock[1][0] != '/')
    tmpdir = cd_progressive(exe, cmd);
  else
    tmpdir = strdup(cmd->stock[1]);
  if (!(tmpdir) || change_dir(tmpdir) == B_FAILURE)
    return (B_FAILURE);
  return (actualise_pwd(exe));
}
