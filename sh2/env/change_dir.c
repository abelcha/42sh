/*
** change_dir.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/env
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:48:28 2014 chalie_a
** Last update Sun Mar  9 22:48:28 2014 chalie_a
*/

#include <stdlib.h>
#include "mysh.h"
#include "env.h"
#include "x_error.h"

static int	to_pwd(char *str, char **env)
{
  char		*dup;
  int		i;

  i = change_in_tab(env, "PWD=");
  if (change_dir_tech(str) == SUCCESS)
    if (i != NONE)
      {
	pwd_to_old(env, i);
	dup = my_strcat("PWD=", str);
	free(env[i]);
	env[i] = dup;
	return (SUCCESS);
      }
  return (FAILURE);
}

static int	go_back(char **env)
{
  int		i;
  int		j;
  char		*str;

  i = change_in_tab(env, "PWD=");
  if (i == NONE)
    return (FAILURE);
  j = my_strlen(env[i]);
  while (env[i][j] != '/' && env[i][j - 2] != '=')
    j--;
  if (j > 2)
    {
      change_dir_tech("..");
      pwd_to_old(env, i);
      str = my_strndup(env[i], j);
      free(env[i]);
      env[i] = str;
    }
  return (SUCCESS);
}

static int	go_before(char	**env)
{
  int		i;
  int		j;
  char		*str;

  i = change_in_tab(env, "PWD=");
  j = change_in_tab(env, "OLDPWD=");
  if (j == NONE || i == NONE)
    return (FAILURE);
  free(env[i]);
  env[i] = my_strdup(&(env[j][3]));
  str = my_strdup(get_env(env, "OLDPWD="));
  free(env[i]);
  env[i] = my_strdup(&(env[j][3]));
  to_pwd(str, env);
  free(str);
  return (SUCCESS);
}

static int	special_dir(char **env, char c)
{
  if (c == '~')
    if (change_in_tab(env, "HOME=") == -1)
      my_putstr(VA_HOME);
    else
      return (to_pwd((get_env(env, "HOME=")), env));
  else if (c == '-')
    if (change_in_tab(env, "OLDPWD=") == -1)
      my_putstr(VA_OP);
    else
      return (go_before(env));
  else if (c == '/')
    return (to_pwd("/", env));
  return (FAILURE);
}

int		change_dir(char **stock, char **env)
{
  char		*str;

  if (stock[2])
    return (FAILURE);
  else if (!stock[1])
    return (special_dir(env, '~'));
  if (stock[1][1] == '\0')
    return (special_dir(env, stock[1][0]));
  else if (stock[1][0] == '.' && stock[1][1] == '.' && stock[1][2] == '\0')
    return (go_back(env));
  else if (stock[1][0] == '/')
    return (to_pwd(stock[1], env));
  else
    {
      str = my_pathcat(get_env(env, "PWD="), stock[1]);
      to_pwd(str, env);
      free(str);
    }
  return (SUCCESS);
}
