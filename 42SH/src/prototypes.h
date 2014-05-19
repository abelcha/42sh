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
