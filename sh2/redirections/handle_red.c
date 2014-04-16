/*
** handle_red.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/redirections
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:51:14 2014 chalie_a
** Last update Sun Mar  9 22:51:14 2014 chalie_a
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "x_error.h"
#include "mysh.h"

static int	open_red(int output, char *filename, int mode)
{
  int		save;
  int		newfd;

  if (mode == 0)
    return (-1);
  save = dup(output);
  newfd = open(filename, mode, 0644);
  x_free(filename);
  if (newfd < 0)
    return (ERROR(O_FAIL));
 if (dup2(newfd, output) < 0)
    return (ERROR(DUP_FAIL));
  return (save);
}

static int	open_in_red(char *filename)
{
  int		save;
  int		newfd;

  save = dup(STDIN_FILENO);
  newfd = open(filename, O_RDONLY);
  if (newfd < 0)
    return (ERROR(NOFILE));
  if (dup2(newfd, STDIN_FILENO) < 0)
    return (ERROR(DUP_FAIL));
  return (save);
}

static int	read_while(char *name)
{
  char		*s;
  int		fd;
  char		c;

  c = '\n';
  fd = open(TMP_FILE, O_CREAT | O_TRUNC | O_WRONLY, 0644);
  if (fd < 0)
    return (FAILURE);
  while ((s = gnl(0)))
    {
      if (!my_strcmp(name, s))
	{
	  free(s);
	  break ;
	}
      else
	write(fd, s, my_strlen(s));
      write(fd, &c, 1);
      free(s);
    }
  close(fd);
  return (open_in_red(TMP_FILE));
}

int		*red_action(t_dll *list)
{
  int		*saves;

  saves = malloc(4 * sizeof(int));
  if (!saves)
    return (NULL);
  saves[0] = -1;
  saves[1] = -1;
  saves[2] = -1;
  if (list->in_red != -1)
    {
      if (list->in_red == -66)
	saves[0] = read_while(list->file_name[INP]);
      else
	saves[0] = open_in_red(list->file_name[INP]);
      x_free(list->file_name[INP]);
   }
  if (list->out_red != -1)
    saves[1] = open_red(STDOUT_FILENO, list->file_name[OUTP], list->out_red);
  if (list->err_red != -1)
    saves[2] = open_red(STDERR_FILENO, list->file_name[OUTP], list->in_red);
  return (saves);
}
