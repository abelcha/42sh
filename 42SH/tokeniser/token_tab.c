/*
** lexer.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Apr 20 09:52:11 2014 chalie_a
** Last update Tue Apr 22 07:08:42 2014 chalie_a
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
   "ROOT",
   "END_OF_LINE"};
