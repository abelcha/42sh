/*
** env_tech.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/env
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:49:02 2014 chalie_a
** Last update Sun Mar  9 22:49:02 2014 chalie_a
*/

#include "mysh.h"
#include "env.h"
#include "stdlib.h"

char		**ptr_dup(char **stock)
{
  int		i;
  char		**copy;
  int		len;

  i = 1;
  len = 0;
  while (stock[len])
    len++;
  if (my_realset(&copy, len) == NULL)
    exit(-1);
  while (stock[i - 1] && i <= len && i < BUFF_SIZE)
    {
      copy[i] = x_malloc(my_strlen(stock[i - 1]) + 1);
      my_strcpy(copy[i], stock[i - 1]);
      i++;
    }
  copy[i] = NULL;
  return (copy);
}

int		my_egualen(const char *str)
{
  int		i;

  i = 1;
  while (str[i])
    {
      if (str[i] == '=')
	return (i);
      i++;
    }
  return (NONE);
}

char	**add_in_tab(char **stock, char *str)
{
  int	len;

  len = my_atoi(stock[0]);
  if (len > BUFF_SIZE - 2)
    return (stock);
  free(stock[len]);
  stock[len] = my_strdup(str);
  stock[len + 1] = NULL;
  free(stock[0]);
  stock[0] = my_itoa(len + 1);
  return (stock);
}

char	**del_in_tab(char **stock, char *str)
{
  int	i;
  int	len;
  char	*cat;

  len = my_atoi(stock[0]);
  cat = my_strcat(str, "=");
  i = change_in_tab(stock, cat);
  free(cat);
  if (i ==  -1)
      return (NULL);
  free(stock[i]);
  while (i < len)
    {
      stock[i] = stock[i + 1];
      i++;
    }
  stock[i] = NULL;
  free(stock[0]);
  stock[0] = my_itoa(len - 1);
  return (stock);
}

int	change_in_tab(char **stock, char *str)
{
  int	i;
  int	len;

  i = 0;
  len = my_egualen(str);
  if (len == -1)
    return (-2);
  while (stock[i])
    {
      if (!my_strncmp(str, stock[i], my_egualen(str))
	  && stock[i][len] == '=')
	return (i);
      i++;
    }
  return (NONE);
}
