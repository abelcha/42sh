
CC		=	clang -g3

NAME		=	42sh

SRC		=	./main.c				\


LIB		=	./lib/free_utils.c			\
			./lib/strmatch.c			\
			./lib/my_atoi.c				\
			./lib/gnl.c				\


PARSER		=	./parser_lexer/free_parse_tree.c	\
			./parser_lexer/create_new_tree_node.c	\
			./parser_lexer/semantic_analyser.c	\
			./parser_lexer/display.c		\
			./parser_lexer/get_paths.c		\
			./parser_lexer/create_cmd_node.c	\
			./parser_lexer/handle_redirections.c	\
			./parser_lexer/main_parsing.c		\
			./parser_lexer/find_cmd_path.c		\
			./parser_lexer/add_tokens_in_node.c	\

TOKEN		=	./tokeniser/tokeniser.c			\
			./tokeniser/token_tab.c			\
			./tokeniser/parser_tokenizer.c		\
			./tokeniser/add_tokens_in_list.c	\


RED		=	./redirections/main_redirections.c	\

EXE		=	./execution/exec_main.c			\
			./execution/exec_loop.c			\


LINE		=	./line_edition/add_del_key_actions.c	\
			./line_edition/get_line_caps.c		\
			./line_edition/history_key_actions.c	\
			./line_edition/arrow_key_action.c	\
			./line_edition/init_termcaps.c		\

HIST		=	./history/init_history.c		\
			./history/put_in_history.c		\

GLOB		=	#./globbing/main_globbing.c		\

BUILD		=	./builtins/env_dll.c			\
			./builtins/builtins.c			\


OBJ		=	$(SRC:.c=.o) $(LIB:.c=.o) 

P_OBJ		=	$(TOKEN:.c=.o) $(PARSER:.c=.o)

SH_OBJ		=	$(RED:.c=.o) $(BUILD:.c=.o) $(EXE:.c=.o)

B_OBJ		=	$(LINE:.c=.o) $(HIST:.c=.o) $(GLOB:.c=.o)

ALL_OBJ		=	$(OBJ) $(P_OBJ) $(SH_OBJ) $(B_OBJ)

CFLAGS	=	-I./includes -Wall -Wextra -pedantic

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
