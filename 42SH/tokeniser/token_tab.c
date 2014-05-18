/*
** lexer.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Apr 20 09:52:11 2014 chalie_a
** Last update Sat May 17 09:59:27 2014 chalie_a
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
