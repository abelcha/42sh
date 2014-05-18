/*
** cd.c for 42sh in /home/coutar_a/rendu/42sh/42SH/builtins
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Sat May 17 14:24:19 2014 coutar_a
** Last update Sun May 18 10:10:54 2014 chalie_a
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "sh.h"

int		cd_home(t_execution *exe, t_cmd *cmd)
{
  char		*oldpwd;
  char		*pwd;
  t_env_dll	*tmp;
  t_env_dll	*tmp2;

  (void)cmd;
  if (!(tmp = search_for_env_variable("HOME", exe->env->env_dll)) ||
      !(tmp2 = search_for_env_variable("PWD", exe->env->env_dll)))
    return (-1);
  chdir(tmp->value);
  pwd = get_env_line("PWD", tmp->value);
  oldpwd = get_env_line("OLDPWD", tmp2->value);
  free(tmp2->name);
  fill_env_struct(tmp2, pwd);			//<<- SEGFAULT si pwd == NULL
  if(!(tmp = search_for_env_variable("OLDPWD", exe->env->env_dll)))
    add_env_variable(exe->env->env_dll, oldpwd);
  else
    {
      free(tmp->name);
      fill_env_struct(tmp, oldpwd);		//<<- SEGFAULT si pwd == NULL
    }
  put_env_in_tab(exe->env);
  return (0);
}

int		cd_progressive(t_execution *exe, t_cmd *cmd)
{
  char		*pwd;
  char		*oldpwd;
  t_env_dll	*tmp;
  t_env_dll	*tmp2;

  if (!(tmp = search_for_env_variable("PWD", exe->env->env_dll)))
    return (-1);
  if ((chdir(cmd->stock[1])) == -1)
    return (cd_chdir_error());
  if (!(pwd = get_env_line("PWD",supercat(tmp->value, "/", cmd->stock[1])))) // <<- SEGFAULT si supercat == NULL
    return (-1);
  oldpwd = get_env_line("OLDPWD", tmp->value);
  free(tmp->name);
  fill_env_struct(tmp, pwd);
  if(!(tmp2 = search_for_env_variable("OLDPWD", exe->env->env_dll)))
    add_env_variable(exe->env->env_dll, oldpwd);
  else
    {
      free(tmp2->name);
      fill_env_struct(tmp2, oldpwd);
    }
  put_env_in_tab(exe->env);
  return (0);
}

int	cd_absolute(t_execution *exe, t_cmd *cmd)
{
  char		*pwd;
  char		*oldpwd;
  t_env_dll	*tmp;
  t_env_dll	*tmp2;

  if (!(tmp = search_for_env_variable("PWD", exe->env->env_dll)))
    return (-1);
  if ((chdir(cmd->stock[1])) == -1)
    return (cd_chdir_error());
  pwd = get_env_line("PWD", cmd->stock[1]);
  oldpwd = get_env_line("OLDPWD", tmp->value);
  free(tmp->name);
  fill_env_struct(tmp, pwd);
  if(!(tmp2 = search_for_env_variable("OLDPWD", exe->env->env_dll)))
    add_env_variable(exe->env->env_dll, oldpwd);
  else
    {
      free(tmp2->name);
      fill_env_struct(tmp2, oldpwd);
    }
  put_env_in_tab(exe->env);
  return (0);
}

int	cd_regressive(t_execution *exe, t_cmd *cmd)
{
  char		*pwd;
  char		*oldpwd;
  t_env_dll	*tmp;
  t_env_dll	*tmp2;

  if (!(tmp = search_for_env_variable("PWD", exe->env->env_dll)))
    return (-1);
  oldpwd = get_env_line("OLDPWD", tmp->value);
  pwd = get_env_line("PWD", cd_arbor_regress(tmp->value));	 // <<- DOUBLE SEGFAULT
  if ((chdir(cmd->stock[1])) == -1)
    return (cd_chdir_error());
  free(tmp->name);
  fill_env_struct(tmp, pwd);
  if(!(tmp2 = search_for_env_variable("OLDPWD", exe->env->env_dll)))
    add_env_variable(exe->env->env_dll, oldpwd);
  else
    {
      free(tmp2->name);
      fill_env_struct(tmp2, oldpwd);
    }
  put_env_in_tab(exe->env);
  return (0);
}

int	cd_other(t_execution *exe, t_cmd *cmd, int check)
{
  int	errno;

  errno = 0;
  if ((access(cmd->stock[1], F_OK | R_OK | W_OK)) == -1)
    {
      if (errno == ENOENT) 
	printf("Folder not found.\n");
      if (errno == ENOTDIR)
	printf("Error : %s is not a directory.\n", cmd->stock[1]);
      return (-1);
    }
  if ((strcmp("..", cmd->stock[1])) != 0)
    {
      if (check == 0 || check == 1)
	return (cd_progressive(exe, cmd));
      return (cd_absolute(exe, cmd));
    }
  return(cd_regressive(exe, cmd));
}
