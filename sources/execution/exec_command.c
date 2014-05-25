/*
** exec2.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/execution
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:40:44 2014 chalie_a
** Last update Sun May 25 22:31:03 2014 chalie_a
*/

#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include "sh.h"
#include "parser.h"
#include "tokenizer.h"

int		exec_command(t_cmd *tmp, t_execution *exe)
{
  if (tmp->builtin == -1 &&
      execve(tmp->path, tmp->stock, exe->env->envp) == FAILURE)
    {
      exe->exit = FAILURE;
      return (ERRNO);
    }
  else
    exec_builtins(tmp, exe);
  return (SUCCESS);
}
