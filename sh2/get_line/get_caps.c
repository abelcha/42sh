/*
** get_caps.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/get_line
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:49:23 2014 chalie_a
** Last update Sun Mar  9 22:49:23 2014 chalie_a
*/

#include <signal.h>
#include <stdlib.h>
#include "mysh.h"
#include "x_error.h"
#include "get_caps.h"
#include "gnl_caps.h"

int		is_legit(const char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    if (str[i] != ' ' && str[i] != '\t')
      return (TRUE);
  return (FALSE);
}

char		*get_lucky(char **env)
{
  char		*buffer;
  static char	**buff_history = NULL;
  static int	i = -1;

  if (buff_history && env == NULL)
    {
      double_free(buff_history);
      return (NULL);
    }
  pos = 0;
  prompt(env, ++i);
  if (buff_history == NULL)
    {
      buff_history = x_malloc(MEM_POOL * sizeof(char *));
      my_meminit(buff_history, MEM_POOL);
      what_a_filling(&buff_history);
    }
  if (!(buffer = malloc(BUFF_SIZE * sizeof(char))))
    return (NULL);
  if (caps_read(&buffer, buff_history) == FAILURE)
    return (NULL);
  push_up(&buff_history, buffer);
  if (buffer)
    history_fputs(buffer);
  return (is_legit(buffer) == FALSE ? NULL : buffer);
}

int		main(int argc, char **argv, char **env)
{
  char		**ptr;
  int		exit_nbr;

  if (!(argc) && argv)
    return (0);
  force_exit = FALSE;
  if (set_termcaps(env) == FAILURE)
    return (ERROR(SET_FAIL));
  signal(SIGINT, SIG_IGN);
  if ((ptr = ptr_dup(env)))
    exit_nbr = jackie_minishell(ptr);
  else
    return (ERROR(ENV_FAIL));
  unset_termcaps();
  double_free(ptr);
  get_lucky(NULL);
  return (exit_nbr);
}
