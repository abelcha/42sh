/*
** handle_redirections_del.c for Project-Master in /home/beau_v/rendu/42SH/42sh/42SH/parser_lexer
** 
** Made by beau_v
** Login   <victor.beau@epitech.eu>
** 
** Started on  Mon May 19 18:26:20 2014 beau_v
** Last update Mon May 19 18:27:14 2014 beau_v
*/

#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "parser.h"

int		delete_filename_token(t_token *token, int flag)
{
  token->prev->next = token->next;
  token->next->prev = token->prev;
  if (flag)
    free(token);
  else
    token->data = NULL;
  token = NULL;
  return (SUCCESS);
}

int		double_left(t_red *red)
{
  if (read_while(red) == FAILURE)
    return (FAILURE);
  red->token = 1;
  red->name = TMP_FILE;
  return (SUCCESS);
}
