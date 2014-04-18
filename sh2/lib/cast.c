/*
** cast.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/lib
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:50:35 2014 chalie_a
** Last update Sun Mar  9 22:50:35 2014 chalie_a
*/

#include "mysh.h"

int	cast(void *ptr)
{
  if (ptr)
    return (SUCCESS);
  else
    return (FAILURE);
}
