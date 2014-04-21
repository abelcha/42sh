/*
** lexer.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Apr 20 09:52:11 2014 chalie_a
** Last update Mon Apr 21 00:06:24 2014 chalie_a
*/

#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "parser.h"

extern const char		*token_tab[T_NBR + 1];

int			lex_error(int tk1, int tk2)
 {
   char			*unexpected_token;

   if (tk2 == T_EOL)
     return (tk1 == T_SEM ? SUCCESS : lex_error(tk1, ++tk2));
   fprintf(stderr, "Syntax Error : unexpected token '%s' after '%s'\n", 
	   token_tab[tk2], token_tab[tk1]);
   return (FAILURE);
 }
