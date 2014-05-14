/*
** utils.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/buildins
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:40:27 2014 chalie_a
** Last update Sun Mar  9 22:40:27 2014 chalie_a
*/

#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"
#include "x_error.h"

static int	fx(const char *env, const char *info, int len)
{
  int		i;

  i = 0;
  while (i < len && info[i] == env[i])
    i++;
  if (i > len - 1)
    return (SUCCESS);
  return (FAILURE);
}

char		*get_env(char **env, char *info)
{
  int		i;
  int		j;

  j = my_strlen(info);
  i = 0;
  while (env && env[i])
    {
      if (fx(env[i], info, j) == 1)
	return (&env[i][j]);
      i++;
    }
  return (info);
}

int		x_error(int flag)
{
  if (flag == 1)
    ERROR(FW_ARGS);
  else if (flag == 2)
    ERROR(VA_ARGS);
  else if (flag == 3)
    ERROR(TMA);
  my_putstr(S_USA);
  return (FAILURE);
}

char		**my_realset(char ***buffer, int i)
{
  if (i > BUFF_SIZE)
    return (NULL);
  if (!(*buffer = malloc(BUFF_SIZE * sizeof(char **))))
    {
      my_putstr("Error : Malloc Failed");
      return (NULL);
    }
  *buffer[0] = my_itoa(i + 1);
  return (*buffer);
}

int		change_dir_tech(char *str)
{
  if (chdir(str))
    {
      my_putstr("cd : `");
      if (str)
        my_putstr(str);
      my_putstr("` no such file or directory\n");
      return (FAILURE);
    }
  return (SUCCESS);
}
