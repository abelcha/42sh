/*
** prototypes.h for 42sh in /data/tek/projects/42sh/42SH/src
** 
** Made by kalatz_a
** Login   <kalatz_a@epitech.net>
** 
** Started on  Wed May 21 16:04:50 2014 kalatz_a
** Last update Wed May 21 16:04:51 2014 kalatz_a
*/

#ifndef PROTOTYPES_H_
# define PROTOTYPES_H_

void	kill_sons(int *pid);
int	signal_ctz(int sig);
int	clean_all(t_execution *exe);
void	link_all_structs(t_execution *exe, t_line *line, t_shell *sh);
t_execution	*init_exe(char **env);
t_line 	*init_sline();
t_jobs	*init_jobs();
t_alias	*init_alias();
t_shell	*init_sh();

#endif /* !PROTOTYPES_H_ */
