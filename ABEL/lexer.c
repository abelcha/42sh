/*
** lexer.c for Project-Master in /home/tovazm/rendu/42sh/ABEL
** 
** Made by chalie_a
** Login   <abel@chalier.me>
** 
** Started on  Sun Apr 20 09:52:11 2014 chalie_a
** Last update Sun Apr 20 15:44:19 2014 chalie_a
*/

#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "parser.h"

static const char           *token_tab[T_NBR] = {
  "&>", "<",
  ">&", ">",
  "||", "|",
  "&&", "&",
  ">>", "`",
  "<<", ";",
  "DATA",
  "END_OF_LINE"};

int			lexical_error(t_cmd *cmd, t_token *token)
{

}

t_parse_tree		*init_tree()
{
  t_parse_tree		*root;

  if (!(root = malloc(sizeof(t_parse_tree))))
    return (NULL);
  root->prev = root;
  root->next = root;
  return (root);
}

int		add_data_in_cmd(t_cmd *cmd, t_token *token)
{
  if (!cmd)
    return (0);
  // fprintf(stderr, "add data in cmd\n");
  cmd->stock[cmd->size] = token->data;
  cmd->stock[cmd->size][token->data_size] = 0;
  ++(cmd->size);
  return (SUCCESS);
}

int		add_token_in_node(t_parse_tree *tmp, t_token *token)
{
//  if (lexical_error(tmp, token) == TRUE)
//   return (FAILURE);
  // fprintf(stderr, "add token in node\n");
  if (token->token == T_PIPE)
    create_new_cmd(tmp->cmd);
  if (token->token == T_CMD)
    add_data_in_cmd(tmp->cmd->prev, token);
   return (SUCCESS);
}

int			create_new_cmd(t_cmd *elem)
{
  t_cmd		*newelem;
  // fprintf(stderr, "create new cmd\n");
  if (!(newelem = calloc(1, sizeof(t_cmd))))
    return (FAILURE);
  newelem->stock = calloc(128, sizeof(char));
  newelem->size = 0;
  newelem->prev = elem->prev;
  newelem->next = elem;
  elem->prev->next = newelem;
  elem->prev = newelem;
  return (SUCCESS);
}


int		fill_tree(t_parse_tree *root, t_token *beg)
{
  t_token	*token;

   token = beg;
   create_new_tree_node(root, token);
   while ((token = token->next) != beg)
     if (token->token == T_SEM || token->token == T_AMP || token->token == T_OR || token->token == T_AND)
       create_new_tree_node(root, token);
     else
       add_token_in_node(root->prev, token);
}

t_cmd		*init_cmd()
{
  t_cmd		*root;

  if (!(root = malloc(sizeof(t_cmd))))
    return (NULL);
  root->prev = root;
  root->next = root;
  return (root);
}


int			create_new_tree_node(t_parse_tree *root, t_token *token)
{
  t_parse_tree		*new;
  t_cmd			*next_elem;

  //fprintf(stderr, "create new tree node\n");
  if (!(new = calloc(1, sizeof(t_parse_tree))))
    return (FAILURE);
  if (!(new->cmd = init_cmd()))
    return (FAILURE);   
  create_new_cmd(new->cmd);
  new->token = token->token;
  new->prev = root->prev;
  new->next = root;
  root->prev->next = new;
  root->prev = new;
  return (SUCCESS);
}

int		display_tree(t_parse_tree *root)
{
  t_parse_tree	*tmp;
  t_cmd		*temp;

  tmp = root->next;
  while (tmp != root)
    {
      printf("==========================\n");
      printf("token = %s\n", token_tab[tmp->token]);
      temp = tmp->cmd;
      while ((temp = temp->next) != tmp->cmd)
	{
	  if (temp != tmp->cmd->next)
	    {
	      //      free(temp->prev->stock);
	      //free(temp->prev);
	      printf("--------------\n");
	    }	  
	  int	i = -1;
	  while (temp->stock[++i])
	    printf("data = %s\n", temp->stock[i]);
	}
      tmp = tmp->next;
      //free(tmp->prev);
    }
}

int		lexical_analysis(t_token *token)
{
  t_parse_tree	*root;

  if (!(root = init_tree()))
    return (FAILURE);
  fill_tree(root, token);
  display_tree(root);
  free(token->data);
  free(token);
  free(root);
}

