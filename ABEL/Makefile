
CC	=	clang -g3

NAME	=	42sh

SRC	=	./free_parse_tree.c\
		./main.c		\
		./exec_loop.c	\
		./env_dll.c	\
		./find_cmd_path.c	\
		./tokeniser.c\
		./add_tokens_in_list.c\
		./token_tab.c\
		./create_new_tree_node.c\
		./builtins.c		\
		./semantic_analyser.c\
		./display.c\
		./parser_tokenizer.c\
		./add_tokens_in_node.c\
		./create_cmd_node.c\
		./handle_redirections.c\
		./main_parsing.c\
		./get_paths.c	\
		./exec_main.c	\

LIB	=	./gnl.c		\
		./free_utils.c	\
		./strmatch.c	\
		./my_atoi.c
OBJ	=	$(SRC:.c=.o) $(LIB:.c=.o)

CFLAGS	=	-I./ #-W -Wall -Wextra -pedantic

RM	=	rm -fr

all	:	$(NAME)

$(NAME)	:	$(OBJ)

		$(CC) -o $(NAME) $(OBJ)

clean	:

		$(RM) $(OBJ)

fclean	:	clean

		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re

.SILENT	:	all clean fclean re
