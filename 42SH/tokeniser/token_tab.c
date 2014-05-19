/*
** lexer.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Apr 20 09:52:11 2014 chalie_a
** Last update Mon May 19 18:38:50 2014 beau_v
*/

#include "tokenizer.h"

const char		*token_tab[T_NBR + 1] =
  {"&>", "`",
   ">&", ";",
   "||", "|",
   "&&", "&",
   ">>", ">",
   "<<", "<",
   "DATA",
   "END_OF_LINE",
   "ROOT"};
