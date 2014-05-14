/*
** globbing.h for sh in /home/chalie_a/rendu/PSU_2013_minishell2/includes
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:52:36 2014 chalie_a
** Last update Sun Mar  9 22:52:36 2014 chalie_a
*/

#ifndef	GLOBBING_H_
# define GLOBBING_H_

# define MEM_POOL	4096
# define NOT_ESCAPED	(i == 1 || stock[i][j - 1] != '\\')
# define GLOB		 "*"
# define NO_ST		"Error, Expected statement after \"<<\".\n"
# define NO_FILE	"Error, Expected filename after \"<\".\n"
# define FILE_NO	"Error, no such file or directory.\n"

char			**rd_handler(char **, int, int);
char			*gnl(int);
char			**read_from_a_file(char **, int, int);
char			**wildcard_handler(char **, int);
char			**realmove(char **, char **, int, int);

#endif	/* !GLOBBING_H_ */
