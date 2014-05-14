/*
** get_switch.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/get_line
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:49:35 2014 chalie_a
** Last update Sun Mar  9 22:49:35 2014 chalie_a
*/

#include <stdlib.h>
#include "mysh.h"
#include "x_error.h"
#include "signal.h"

int		is_legit(const char *str)
{
  int		i;
  int		ret;

  i = -1;
  while (str[++i])
    if ((str[i] < 20 && str[i] < 127))
      return (FAILURE);
    else if (str[i] != ' ' && str[i] != '\t' && str[i] != '|'
	     && str[i] != ';' && str[i] != 'y')
      ret = TRUE;
  if (i != 0)
    return (ret);
  else
    return (FALSE);
}

char		*get_lucky(char **env)
{
  char		*str;
  static int	i = 0;

  while (42)
    {
      prompt(env, ++i);
      if ((str = gnl(0)))
	{
	  if (is_legit(str) == TRUE)
	    return (str);
	  else
	    {
	      if (is_legit(str) == FAILURE)
		arg_error(str);
	      x_free(str);
	    }
	}
      else
        break ;
    }
  my_putstr("\nEOF\n");
  exit(0);
  force_exit = TRUE;
  return (NULL);
}

int		main(int argc, char **argv, char **env)
{
  char		**ptr;

  if (!(argc) && argv)
    return (0);
  force_exit = FALSE;
  signal(SIGINT, SIG_IGN);
  if ((ptr = ptr_dup(env)))
    {
      jackie_minishell(ptr);
      double_free(ptr);
      return (force_exit);
    }
  return (ERROR(ENV_FAIL));
}
