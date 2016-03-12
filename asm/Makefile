##
## Makefile for ASM in /home/bougon_p/rendu/CPE_2015_corewar/asm
##
## Made by bougon_p
## Login   <bougon_p@epitech.net>
##
## Started on  Thu Mar 10 14:59:56 2016 bougon_p
## Last update Sat Mar 12 17:24:53 2016 
##

# USEFUL VARIABLES

RM      =	rm -rf

GREEN	=	\033[1;32m

WHITE	=	\033[0m

ECHO	=	echo -e


# SOURCES VARIABLES

PARSER		=	srcs/parser/

LEXER		=	srcs/lexer/

TOOLS		=	srcs/tools/

ERROR		=	srcs/error/

SRC		=	srcs/main.c \
			srcs/op.c \
			$(PARSER)parser.c \
			$(LEXER)lexer.c \
			$(LEXER)check_name.c \
			$(LEXER)check_comment.c \
			$(LEXER)check_instructions.c \
			$(LEXER)epure_file.c \
			$(LEXER)put_in_list.c \
			$(LEXER)check_char.c \
			$(TOOLS)get_next_line.c \
			$(ERROR)error_stop.c

OBJS    	=	$(SRC:.c=.o)


# LIBRARY VARIABLES

LIBPATH =       lib/

LDFLAGS =       -lmy -L$(LIBPATH)

# PROJECT VARIABLES

NAME	=	asm

IFLAG	=	-Iinclude/

CFLAGS  =	-W -Wall -Wextra $(IFLAG)

CC      =	gcc -g $(CFLAGS)



# PROJECT RULES

$(NAME)		: 	$(OBJS)
			@$(ECHO) "$(GREEN)\n> Compiling project\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"
			@$(CC) -o $(NAME) $(OBJS)

all		:	$(NAME)

clean		:
			@$(RM) $(OBJS)
			@$(ECHO) "$(GREEN)\n> Cleaning repository\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

fclean		: 	clean
			@$(RM) $(NAME)
			@$(ECHO) "$(GREEN)\n> Cleaning exec\t\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

re		:	fclean all

.c.o		:
			@$(CC) -c $< -o $@
			@$(ECHO) "$(GREEN)[OK] > $<\t \t $(WHITE)"
