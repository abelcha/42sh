/*
** mysh.h for mysh in /home/chalie_a/rendu/PSU_2013_minishell1
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sat Dec 28 05:43:11 2013 chalie_a
** Last update Sat Dec 28 05:43:11 2013 chalie_a
*/

#ifndef ENV_H_
# define ENV_H_

int	unset_error(int, char *);
int	pwd_to_old(char **, int);
int	change_dir_tech(char *);
int	change_dir(char **, char **);
int	print_dir(char **, char **);
int	x_error(int);
int	change_in_tab(char **, char *);
int	my_egualen(const char *);
char	*cut_str(char *, int);
int	fx(char *, char *, int);
char	*get_env(char **, char *);
int	print_env(char **, char **);
int	set_env(char **, char **);
int	unset_env(char **, char **);
char	*my_itoa(int);
char	**ptr_dup(char **);
char	**add_in_tab(char **, char *);
char	**del_in_tab(char **, char *);

#endif /* !ENV_H_ */
