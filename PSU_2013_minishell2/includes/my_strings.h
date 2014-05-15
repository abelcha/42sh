/*
** my_strings.h for sh in /home/chalie_a/rendu/PSU_2013_minishell2/includes
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:53:06 2014 chalie_a
** Last update Sun Mar  9 22:53:06 2014 chalie_a
*/

#ifndef MY_STRINGS_H_
# define MY_STRINGS_H_

char	*my_strdup(char *);
char	*my_strndup(char *, int);
int	my_strlen(char *);
char	*my_strcpy(char *, char *);
char	*my_strncpy(char *, char *, int);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
char	*my_strcat(char *, char *);

#endif /* !MY_STRINGS_H_ */
