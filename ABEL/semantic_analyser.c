/*
** lexer.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Apr 20 09:52:11 2014 chalie_a
** Last update Tue Apr 22 07:08:29 2014 chalie_a
*/

#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "parser.h"

extern const char		*token_tab[T_NBR + 1];

int			lex_error(int tk1, int flag, int tk2)
 {
   static const char	*tab[2] = {"before", "after"};

   //   if (tk2 == T_EOL)
   //   return (tk2 == T_SEM ? SUCCESS : lex_error(++tk1, flag, ++tk2));
   fprintf(stderr, "Syntax Error : unexpected token '%s' %s '%s'\n", 
	   token_tab[tk1], tab[flag], token_tab[tk2]);
   return (FAILURE);
 }
