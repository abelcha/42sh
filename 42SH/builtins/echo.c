/*
** echo.c for 42sh in /home/coutar_a/Projets/42sh/42sh/sh2/buildins
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Mon May  5 09:50:58 2014 coutar_a
** Last update Fri May 16 12:59:59 2014 chalie_a
*/

#include <unistd.h>
#include <stdlib.h>
#include "sh.h"

const static t_echo	g_esc[] =
  {
    {'\\', '\\'},
    {'a', '\a'},
    {'b', '\b'},
    {'c', '\c'},
    {'e', '\e'},
    {'f', '\f'},
    {'n', '\n'},
    {'r', '\r'},
    {'t', '\t'},
    {'v', '\v'}
  };

int		find_flags(char **stock, char *flagstatus)
{
  int		i;

  i = -1;
  while (stock[++i] != NULL)
    {
      if((strcmp(stock[i], "-n")) == 0)
	flagstatus[0] = 1;
      if ((strcmp(stock[i], "-e")) == 0)
	flagstatus[1] = 1;
      if ((strcmp(stock[i], "-E")) == 0)
	flagstatus[1] = 0;
    }
  return (0);
}

int	find_strings(char **stock, char *flagstatus)
{
  int	i;

  i = 1;
  while (stock[i] != NULL)
    {
      if ((strcmp(stock[i], "-n")) == 0 ||
	  (strcmp(stock[i], "-e")) == 0 ||
	  (strcmp(stock[i], "-E")) == 0)
	i++;
      else
	{
	  write_echo(stock[i++], flagstatus, g_esc);
	  if (stock[i] != NULL)
	    write(1, " ", 1);
	}
    }
  if (flagstatus[0] == 0)
    write(1, "\n", 1);
    //printf("tamere\n");		 //<<--C'est quoi ce truc qui fout la merde .
  return (0);
}

int	write_echo(char	*str, char *flagstatus, t_echo *g_esc)
{
  int	i;

  i = -1;
  if (flagstatus[1] == 1)
    {
      while (str[++i] != 0)
	{
	   if (str[i] == 92)
	    escape_code_parsing(g_esc, str, &i);
	  else
	    write(1, &str[i], 1);
	}
    }
    else
      write(1, str, strlen(str));
  return (0);
}

int	byte_printer(char *str, int *i)
{
  int	byte;
  char	oct[3];
  char	hex[2];

  if (str[(*i) + 1] == 'x')
    {
      hex[0] = str[(*i) + 2];
      hex[1] = str[(*i) + 3];
      byte = strtol(hex, &hex[2], 16);
      printf("%c", byte);
      (*i) = (*i) + 3;
      return (0);
    }
  else
    {
      oct[0] = str[(*i) + 2];
      oct[1] = str[(*i) + 3];
      oct[2] = str[(*i) + 4];
      byte = strtol(oct, &oct[3], 8);
      printf("%c", byte);
      (*i) = (*i) + 4;
    }
  return (0);
}

int	escape_code_parsing(t_echo *g_esc, char *str, int *i)
{
  int	j;
  char	escape_code[2];

  j = -1;
  escape_code[0] = str[(*i)];
  escape_code[1] = str[(*i) + 1];
  if (escape_code[1] == '0' || escape_code[1] == 'x')
    return (byte_printer(str, i));
  while (escape_code[1] != g_esc[j].second)
    j++;
  printf("%c", g_esc[j].code);
  (*i)++;
  return (0);
}
