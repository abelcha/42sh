/*
** x_error.h for  in /home/chalie_a/rendu/PSU_2013_minishell2/includes
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:53:19 2014 chalie_a
** Last update Sun Mar  9 22:53:19 2014 chalie_a
*/

#ifndef X_ERROR_H_
# define X_ERROR_H_

# define ERROR(s)	put_error(s)
# define ERROR_(s)      put_null_error(s)
# define FAILURE	-1
# define SUCCESS	1
# define END		0
# define RUNNING	42
# define VA_OP		"OLDPWD variable is not set.\n"
# define VA_HOME	"HOME variable is not set.\n"
# define TMA		"too many arguments.\n"
# define S_USA		"Usage : setenv <variable=value>\n"
# define FW_ARGS	"too few arguments.\n"
# define VA_ARGS	"Can't create env variable whitout assigning a value\n"
# define CNF		"Command not found.\n"
# define DUP_FAIL	"Dup Failed\n"
# define NO_FILE	"No Such file or Directory\n"
# define SET_FAIL	"cannot set new terminal environement"
# define O_FAIL		"Cannot open file\n"
# define ENV_FAIL	"Cannot copy environement\n"
# define READ_FAIL	"System call read failed"
# define GNL_FAIL	"Cannot get next line\n"
# define NOFILE		"Expected Filename Afer redirection token\n"
# define FORK_FAIL	"System Call Fork Failed"
# define COL_FAIL	"ioctl cannot get column number"
# define ROW_FAIL	"ioctl cannot get row number"
# define CLEAN_FAIL	"termcaps cannot clear the screen"
# define CURS_FAIL	"termcaps cannot set curser position"
# define GET_ENV	"cannot get termcaps from env"
# define SETCAPS_FAIL	"tcsetattr failed activating termcap"
# define UNSETCAPS_FAIL	"tcsetattr failed desactivating termcaps"
# define PUTSTR_FAIL	"write failed in my_putstr"
# define MALLOC_FAIL	"Malloc Failed"
# define WIN_TOO_SMALL	"The window is too small, list cannot be displayed"

int			put_error(char *);
void			*put_null_error(char *);

#endif /* !X_ERROR_H_ */
