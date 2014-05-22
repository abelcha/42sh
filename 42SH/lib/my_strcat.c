/*
** my_strcat.c for Project-Master in /home/beau_v/rendu/42SH/42sh/42SH/parser_lexer
** 
** Made by beau_v
** Login   <victor.beau@epitech.eu>
** 
** Started on  Mon May 19 18:06:58 2014 beau_v
** Last update Thu May 22 13:41:02 2014 chalie_a
*/

#include <string.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "parser.h"
#include "sh.h"

char			*my_strjoint(char *s1, char *s2)
{
  char			*new;
  int			i;
  int			j;
  int			len;

  i = 0;
  j = 0;
  len = my_strlen(s1) + my_strlen(s2);
  if (!(new = calloc((len + 1), sizeof(char))))
    return (NULL);
  while (s1[i])
    {
      new[i] = s1[i];
      i++;
    }
  while (s2[j])
    {
      new[i + j] = s2[j];
      j++;
    }
  return (new);
}
