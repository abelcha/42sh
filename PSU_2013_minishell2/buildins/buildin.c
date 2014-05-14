/*
** buildin.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/buildins
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:39:16 2014 chalie_a
** Last update Sun Mar  9 22:39:16 2014 chalie_a
*/

#include <stdlib.h>
#include "mysh.h"
#include "env.h"

int		compare(char *command)
{
  short		i;
  char		*tab[FLAGS_NBR];

  i = 1;
  tab[0] = "$$$";
  tab[1] = "cd";
  tab[2] = "setenv";
  tab[3] = "unsetenv";
  tab[4] = "env";
  tab[5] = "exit";
  tab[6] = "pwd";
  while (i < FLAGS_NBR)
    {
      if (!my_strcmp(command, tab[i]))
        return (i);
      else if (command[0] == '$')
        return (0);
      else
        i++;
    }
  return (NONE);
}

int		destination(char **stock, char **env, const int i)
{
  spec_switch[0] = dollar_sign;
  spec_switch[1] = change_dir;
  spec_switch[2] = set_env;
  spec_switch[3] = unset_env;
  spec_switch[4] = print_env;
  spec_switch[5] = exit_program;
  spec_switch[6] = print_dir;
  return (spec_switch[i](stock, env));
}
