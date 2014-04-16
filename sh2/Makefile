##
## Makefile for chaleifaeqdf in /home/chalie_a/sh
## 
## Made by chalie_a
## Login   <chalie_a@epitech.net>
## 
## Started on  Tue Dec 10 15:13:20 2013 chalie_a
## Last update Tue Mar 11 05:36:22 2014 
##

CC	= gcc

CFLAGS	= -Wall -ansi -pedantic -Werror -Wextra -lefence

RM	= rm -fr

TMP	= .sh_history

SRC	= main.c				\

ECHO	= echo

EXE	= execution/exec2.c			\
	  execution/exec_command.c		\

RED	= redirections/close_red.c		\
	  redirections/handle_red.c		\

PL	= parser_lexer/is_command.c		\
	  parser_lexer/parsing.c		\
	  parser_lexer/sq_tab.c			\
	  parser_lexer/tab_to_swt.c		\
	  parser_lexer/redirection_parser.c	\

BUILD	= buildins/exit.c			\
	  buildins/print_env.c			\
	  buildins/buildin.c			\
	  buildins/check_out.c			\
	  buildins/utils.c

READ	= get_line/get_switch.c			\

GLOB	= globbing/globbing_parser.c		\
	  globbing/wildcards.c			\

TCAPS	= get_line/get_caps.c			\
	  gnl_caps/array_op.c			\
	  gnl_caps/x_display.c			\
	  gnl_caps/x_read.c			\
	  termcaps/termcap.c			\
	  termcaps/termc.c

SLEEP	= sleep 1

ENV	= env/env.c				\
	  env/change_dir.c			\
	  env/env_tech.c			\

LIB	= lib/strings2.c			\
	  lib/strings.c				\
	  lib/to_tab.c				\
	  lib/gnl.c				\
	  lib/cast.c				\
	  lib/yes_or_no.c			\
	  lib/puts.c				\
	  lib/my_memset.c			\
	  lib/my_atoi.c				\
	  lib/my_pathcat.c			\
	  lib/double_free.c			\
	  lib/my_itoa.c				\
	  lib/to_wordpoint.c			\
	  lib/my_x.c				\
	  lib/x_error.c				\

CAT	= cat

NAME	= mysh

CFLAGS	+= -I./includes -g3

M1_OBJ	= $(BUILD:.c=.o) $(SRC:.c=.o) $(LIB:.c=.o) $(ENV:.c=.o)

M2_OBJ	= $(RED:.c=.o) $(GLOB:.c=.o) $(PL:.c=.o) $(EXE:.c=.o)

N_OBJ	= $(READ:.c=.o)
T_OBJ	= $(TCAPS:.c=.o)

all:	 $(NAME)

$(NAME): $(N_OBJ) $(M1_OBJ) $(M2_OBJ)
	 $(CC) -o $(NAME) $(M1_OBJ) $(M2_OBJ) $(N_OBJ)

caps	: $(T_OBJ) $(M1_OBJ) $(M2_OBJ)
	 $(CC) -o $(NAME) $(M1_OBJ) $(M2_OBJ) $(T_OBJ) -lncurses
clean:
	 $(RM) $(T_OBJ) $(T_OBJ) $(B_OBJ) $(N_OBJ) $(M1_OBJ) $(M2_OBJ)

fclean:	 clean
	 $(RM) $(NAME)

re:	 fclean all

tmp:	
	 $(RM) $(TMP)

run:	 $(NAME)
	 ./$(NAME)

.PHONY: all clean fclean re
