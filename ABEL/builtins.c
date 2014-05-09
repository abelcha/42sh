/*
** builtins.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Thu May  8 23:49:35 2014 chalie_a
** Last update Sat May 10 00:39:56 2014 chalie_a
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "sh.h"

#define B_SUCCESS	0
#define B_FAILURE	2

int		my_exit(t_execution *exe, t_cmd *cmd)
{
  --(exe->nb_pipes);
  exe->exit = my_atoi(cmd->stock[1]) + 256;
  return (B_SUCCESS);
}

int		my_env(t_execution *exe, t_cmd *cmd)
{
  t_env_dll	*tmp;
  int		i = -1;
  tmp = exe->env->env_dll;
  /*  while ((tmp = tmp->next) != exe->env->env_dll)
      printf("%s--\n", tmp->name);*/
  while (exe->env->envp[++i])
    printf("%s--\n", exe->env->envp[i]);
  return (B_SUCCESS);
}

char		*get_env_line(char *s1, char *s2)
{
  int		i;
  int		j;
  char		*str;

  j = -1;
  i = -1;
  if (!(str = calloc(strlen(s1) + strlen(s2) + 2, sizeof(char))))
    return (NULL);
  while (s1[++i])
    str[i] = s1[i];
  str[i] = '=';
  while (s2[++j])
    str[++i] = s2[j];
  return (str);
}

t_env_dll	*search_for_env_variable(char *str, t_env_dll *root)
{
  t_env_dll	*tmp;
  int		len;

  len = strlen(str);
  tmp = root;
  while ((tmp = tmp->next) != root)
    {
      if (!strncmp(str, tmp->name, len))
	return (tmp);
    }
  return (NULL);
}

int		actualise_path(t_execution *exe, char *str)
{
  double_free(exe->env->paths);
  if (!str)
    exe->env->paths = NULL;
  else if (!(exe->env->paths = get_paths(get_env(exe->env->envp, "PATH="), ':')))
    return (B_FAILURE);
  return (B_SUCCESS);
}

int		my_setenv(t_execution *exe, t_cmd *cmd)
{
  char		*str;
  t_env_dll	*tmp;

  if (!cmd->stock[1] || !cmd->stock[2] || cmd->stock[3])
    return (_ERROR("Error, USAGE : setenv [Name] [Value]\n"));
  if (!(str = get_env_line(cmd->stock[1], cmd->stock[2])))
    return (B_FAILURE);
  if (!(tmp = search_for_env_variable(cmd->stock[1], exe->env->env_dll)))
    add_env_variable(exe->env->env_dll, str);
  else
    {
      free(tmp->name);
      fill_env_struct(tmp, str);
    }
  put_env_in_tab(exe->env);
  if (!strncmp(str, "PATH=", 5))
    actualise_path(exe, str);
  return (B_SUCCESS);
}

int		my_unsetenv(t_execution *exe, t_cmd *cmd)
{
  t_env_dll	*tmp;

  if (!cmd->stock[1] || cmd->stock[2])
    return (_ERROR("Error, USAGE : setenv [Name]\n"));
  if (!(tmp = search_for_env_variable(cmd->stock[1], exe->env->env_dll)))
    return (_ERROR("Error, Unkown variable `%s'\n", cmd->stock[1]));
  tmp->prev->next = tmp->next;
  tmp->next->prev = tmp->prev;
  x_free(tmp->name);
  x_free(tmp);
  put_env_in_tab(exe->env);
  if (!strncmp(cmd->stock[1], "PATH", 4))
    actualise_path(exe, NULL);
  return (B_SUCCESS);
}

int		my_echo(t_execution *exe, t_cmd *cmd)
{
  printf("yolo\n");
  printf("lalila\n");
  printf("cooucou\n");
  return (B_SUCCESS);
}


int		my_cd(t_execution *exe, t_cmd *cmd)
{
  return (B_SUCCESS);
}
