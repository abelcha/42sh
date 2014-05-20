

CC		=	gcc -g3

NAME		=	42sh

SRC		=	./src/main.c				\
			./src/signal.c				\
			./src/init_structs.c			\
			./src/clean_all.c			\
			./src/parse_config_file.c		\
			./src/alias.c				\

LIB		=	./lib/gnl.c				\
			./lib/my_atoi.c				\
			./lib/strmatch.c			\
			./lib/free_utils.c			\
			./lib/my_strlen.c			\
			./lib/to_tab.c				\
			./lib/my_strcat.c			\
			./lib/my_itoa.c				\

PARSER		=	./parser_lexer/get_paths.c		\
			./parser_lexer/main_parsing.c		\
			./parser_lexer/free_parse_tree.c	\
			./parser_lexer/semantic_analyser.c	\
			./parser_lexer/create_new_tree_node.c	\
			./parser_lexer/handle_redirections.c	\
			./parser_lexer/handle_red_del.c		\
			./parser_lexer/add_tokens_in_node.c	\
			./parser_lexer/create_cmd_node.c	\
			./parser_lexer/find_cmd_path.c		\

TOKEN		=	./tokeniser/tokeniser.c			\
			./tokeniser/token_tab.c			\
			./tokeniser/parser_tokenizer.c		\
			./tokeniser/add_tokens_in_list.c	\


RED		=	./redirections/main_redirections.c	\

EXE		=	./execution/exec_main.c			\
			./execution/exec_loop.c			\

LINE		=	./line_edition/add_del_key_actions.c	\
			./line_edition/history_key_actions.c	\
			./line_edition/start_end_actions.c	\
			./line_edition/arrow_key_action.c	\
			./line_edition/init_termcaps.c		\
			./line_edition/get_line_caps.c		\
			./line_edition/word_action.c		\
			./line_edition/line_utils.c		\

HIST		=	./history/put_in_history.c		\
			./history/init_history.c		\

PRE		=	./pre_parsing/pre_parsing.c		\

GLOB		=	./globbing/main_glob.c			\
			./globbing/tab_glob.c			\
			./globbing/get_cmd_data.c		\
			./globbing/display_results.c		\
			./globbing/get_data_type.c		\

BUILD		=	./builtins/env_dll.c			\
			./builtins/env_builtins.c		\
			./builtins/builtins.c			\
			./builtins/echo.c 			\
			./builtins/cd.c				\

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

clean	:

		$(RM) $(ALL_OBJ)

fclean	:	clean

		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re

.SILENT	:	all clean fclean re
