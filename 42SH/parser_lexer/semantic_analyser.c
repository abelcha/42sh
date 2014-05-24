/*
** lexer.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel.chalier@epitech.eu>
** 
** Started on  Sun Apr 20 09:52:11 2014 chalie_a
** Last update Sat May 24 18:31:24 2014 chalie_a
*/

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "tokenizer.h"

extern const char	*token_tab[T_NBR + 1];

int				lex_error(int tk1, int flag, int tk2)
{
  static const char		*ab_tab[2] = {"before", "after"};

   if (tk2 == T_EOL && flag == AFTER)
     return (lex_error(tk1, flag, ++tk2));
   fprintf(stderr, "Syntax Error : unexpected token `%s' %s `%s'\n",
	   token_tab[tk1], ab_tab[flag], token_tab[tk2]);
   return (FAILURE);
 }
