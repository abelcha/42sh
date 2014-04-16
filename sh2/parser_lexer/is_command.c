/*
** is_command.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/parser_lexer
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:43:58 2014 chalie_a
** Last update Sun Mar  9 22:43:58 2014 chalie_a
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include "mysh.h"
#include "x_error.h"

#define ISPATH(c)	c == '.' || c == '/' ? FALSE :  TRUE

int	is_command(char **path, char *name)
{
  int	i;
  char	*str;

  i = 0;
  if (is_legit(name) == FALSE)
    return (FALSE);
  if (((name[0] == '.' && name[1] == '/') || name[0] == '/')
      &&  (access(name, X_OK) == 0))
    return (TRUE);
  while (path[i])
    {
     str = my_strcat(path[i], name);
     if (access(str, X_OK) == 0)
       {
	 x_free(str);
	 return (TRUE);
       }
     i++;
     x_free(str);
    }
  return (FALSE);
}
