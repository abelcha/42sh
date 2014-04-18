/*
** mysh.h for h in /home/chalie_a/rendu/PSU_2013_minishell2/includes
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:52:53 2014 chalie_a
** Last update Sun Mar  9 22:52:53 2014 chalie_a
*/

#ifndef MYSH_H_
# define MYSH_H_

# define BUFF_SIZE	1024
# define YES		684
# define NO		876
# define FLAGS_NBR	7
# define NONE		-1
# define SUCCESS	1
# define OUTP		1
# define INP		0
# define FORCE_EXIT	-2
# define LEGIT		48
# define FAILURE	-1
# define TRUE		0
# define FALSE		1
# define TMP_FILE	 "/tmp/.red"
# define REDIRECTION	(status = is_a_redirection(stock)) >= 0
# define PIPE		is_a_pipe(stock) >= 0
# define PATHS		to_wordpoint(get_env(env, "PATH="), ':')
# define FILENAME	stock[status + 1]
# define ESCP(s, i)	i == 0 ? FALSE : s[i - 1] != '\\' ? FALSE : TRUE
# define CHEVRON	stock[status]
# define SIMPLE_RED__	O_CREAT|O_TRUNC|O_WRONLY
# define __SIMPLE_RED	O_RDONLY
# define DOUBLE_RED__	O_CREAT|O_APPEND|O_WRONLY
# define __DOUBLE_RED	-66
# define KIND		(*status)[2]

# include "my.h"
# include "parser_lexer.h"

char	*get_lucky(char **);
void	arg_error(char *);
void	*x_calloc(int, int);
char	***tab_to_swt(char **, int, char **, char **);
int	cast(void *);
int	x_open(const char *);
int	is_legit(const char *str);
int	exec_command(char **, char **, char **);
int	exec_pipe(char ***, int, char **, char **);
int	*red_action(t_dll *list);
void	my_puterr(char *);
char	**globbing_parser(char **);
t_dll	*handle_red(char **, t_dll *);
int	x_free(void *);
int	close_all(int *);
t_dll	*command_parsing(char *, char **, char **);
char	****cw_tab(char *, char **, char **);
int	x_free(void *);
char	*gnl(int);
int	jackie_minishell(char **);
char	*my_itoa(int);
int	dollar_sign(char **, char **);
char	**ptr_dup(char **);
char	*get_env(char **, char *);
int	handle_redirections(int, char **, char **);
int	is_a_redirection(char **);
char	**to_tab(char *, int, char);
int	x_execve(char **, char **, char *, char **);
char	*gnl(int);
void	double_free(char **);
int	unset_error(int, char *);
int	destination(char **, char **, int);
int	my_atoi(char *);
int	is_command(char **, char *);
int	aff_command(char **, char **, char **);
void	*x_malloc(int);
int	x_read(int, char *, int);
char	**my_realset(char ***, int);
char	**to_wordpoint(char *, char);
int	(*spec_switch[7])(char **, char **);
void	prompt(char **, int);
char	*my_memset(char *, char, int);
void	sig_handler(int);
void	quad_free(char ****);
void	triple_free(char ***);
void	free_all(char **, char **);
int	compare(char *);
int	exit_program(char **, char **);
char	*get_lucky();
int	x_error(int);
void	exit_like_a_boss(char **);
char	*my_pathcat(char *, char *);
int	force_exit;

#endif /* !MYSH_H_ */
