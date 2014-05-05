/*
** exit.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/buildins
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:39:45 2014 chalie_a
** Last update Sun Mar  9 22:39:45 2014 chalie_a
*/

#include "mysh.h"

int	exit_program(char **stock, char **env)
{
  cast(env);
  force_exit = my_atoi(stock[1]);
  force_exit == 1 ? force_exit = 0 : 0;
  return (SUCCESS);
}
