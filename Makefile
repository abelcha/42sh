## Makefile.c for Project-Master in /mnt/home/tovazm/rendu/42sh/42SH
## 
## Made by chalie_a
## Login   <abel.chalier@epitech.eu>
## 
## Started on  Sat May 24 18:06:02 2014 chalie_a
## Last update Sun May 25 22:11:46 2014 chalie_a
##

CC		=	gcc

NAME		=	42sh

SRC		=	sources/src/main.c				\
			sources/src/signal.c				\
			sources/src/init_structs.c			\
			sources/src/clean_all.c				\
			sources/src/parse_config_file.c			\
			sources/src/fill_config_file.c			\

LIB		=	sources/lib/gnl.c				\
			sources/lib/my_atoi.c				\
			sources/lib/strmatch.c				\
			sources/lib/free_utils.c			\
			sources/lib/to_tab.c				\
			sources/lib/my_strcat.c				\
			sources/lib/my_itoa.c				\
			sources/lib/get_cols.c				\
			sources/lib/t_cap.c				\
			sources/lib/my_memset.c				\
			sources/lib/my_strings.c			\
			sources/lib/my_nstrings.c			\

PARSER		=	sources/parser_lexer/get_paths.c		\
			sources/parser_lexer/main_parsing.c		\
			sources/parser_lexer/free_parse_tree.c		\
			sources/parser_lexer/semantic_analyser.c	\
			sources/parser_lexer/create_new_tree_node.c	\
			sources/parser_lexer/handle_redirections.c	\
			sources/parser_lexer/handle_red_del.c		\
			sources/parser_lexer/add_tokens_in_node.c	\
			sources/parser_lexer/create_cmd_node.c		\
			sources/parser_lexer/find_cmd_path.c		\

TOKEN		=	sources/tokeniser/tokeniser.c			\
			sources/tokeniser/token_tab.c			\
			sources/tokeniser/parser_tokenizer.c		\
			sources/tokeniser/add_tokens_in_list.c		\


RED		=	sources/redirections/main_redirections.c	\

EXE		=	sources/execution/exec_main.c			\
			sources/execution/exec_loop.c			\
			sources/execution/exec_command.c		\

LINE		=	sources/line_edition/add_del_key_actions.c	\
			sources/line_edition/history_key_actions.c	\
			sources/line_edition/start_end_actions.c	\
			sources/line_edition/arrow_key_action.c		\
			sources/line_edition/arrow_key_tabs.c		\
			sources/line_edition/init_termcaps.c		\
			sources/line_edition/get_line_caps.c		\
			sources/line_edition/word_action.c		\
			sources/line_edition/line_utils.c		\

HIST		=	sources/history/add_in_history.c		\
			sources/history/read_history_file.c		\

PRE		=	sources/pre_parsing/pre_parsing.c		\
			sources/pre_parsing/pre_parsing_fonctions.c	\
			sources/pre_parsing/globbing.c			\
			sources/pre_parsing/alias.c			\
			sources/pre_parsing/get_double_alias.c		\

GLOB		=	sources/globbing/tab_glob.c			\
			sources/globbing/get_cmd_data.c			\
			sources/globbing/display_results.c		\
			sources/globbing/get_data_type.c		\
			sources/globbing/add_possibilities.c		\

BUILD		=	sources/builtins/env_dll.c			\
			sources/builtins/env_builtins.c			\
			sources/builtins/builtins.c			\
			sources/builtins/echo.c 			\
			sources/builtins/echo_string.c			\
			sources/builtins/cd.c				\
			sources/builtins/change_dir.c			\

OBJ		=	$(SRC:.c=.o) $(LIB:.c=.o)

P_OBJ		=	$(PRE:.c=.o) $(PARSER:.c=.o) $(TOKEN:.c=.o)

SH_OBJ		=	$(RED:.c=.o) $(BUILD:.c=.o) $(EXE:.c=.o)

B_OBJ		=	$(LINE:.c=.o) $(HIST:.c=.o) $(GLOB:.c=.o)

ALL_OBJ		=	$(OBJ) $(P_OBJ) $(SH_OBJ) $(B_OBJ)

CFLAGS	=	-I./includes -Wall -Wextra

RM	=	rm -fr

all	:	$(NAME)

$(NAME)	:	$(ALL_OBJ)
		$(CC) -o $(NAME) $(ALL_OBJ) -lncurses
		@cat header
clean	:
		$(RM) $(ALL_OBJ)

fclean	:	clean

		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
