##
## Makefile for ASM in /home/bougon_p/rendu/CPE_2015_corewar/asm
##
## Made by bougon_p
## Login   <bougon_p@epitech.net>
##
## Started on  Thu Mar 10 14:59:56 2016 bougon_p
## Last update Fri Mar 11 10:27:58 2016 
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

SRC		=	$(PARSER)parser.c \
			$(LEXER)lexer.c \
			$(LEXER)check_name.c \
			$(LEXER)check_comment.c \
			$(LEXER)check_instructions.c \
			$(TOOLS)get_next_line.c

OBJS    	=	$(SRC:.c=.o)


# LIBRARY VARIABLES

LIBPATH =       lib/

LDFLAGS =       -lmy -L$(LIBPATH)

# PROJECT VARIABLES

NAME	=	asm

IFLAG	=	-Iinclude/

CFLAGS  =	-W -Wall -Wextra -g $(IFLAG)

CC      =	gcc $(CFLAGS)



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
