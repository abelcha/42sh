/*
** lexer.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Apr 20 09:52:11 2014 chalie_a
** Last update Tue May  6 12:31:12 2014 chalie_a
*/

#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "parser.h"

extern const char		*token_tab[T_NBR + 1];

void		display_tree(t_parse_tree *root)
{
  t_parse_tree	*tmp;
  t_cmd		*temp;

    tmp = root->next;
    while (tmp != root)
    {
      //  printf("==========================\n");
      //printf("token = %s\n", token_tab[tmp->token]);
      temp = tmp->cmd;
      while ((temp = temp->next) != tmp->cmd)
	{
	  //if (temp != tmp->cmd->next)
	  //   printf("|||||PIPE||||\n");
	  if (temp->background == 1)
	    printf("========> BACKGROUND\n");
	  //	  int	i = -1;
	  //	  while (temp->stock && temp->stock[++i])
	  //  printf("data = %s\n", temp->stock[i]);
	  if (temp->red)
	    while (temp->red->next->name)
	      {
		printf("---------------> token =  '%s' with  %s\n", 
		       token_tab[temp->red->next->token], temp->red->next->name);
		temp->red = temp->red->next;
	      }
	}
      tmp = tmp->next; 
      }
}
