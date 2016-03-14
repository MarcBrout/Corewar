##
## Makefile for ASM in /home/bougon_p/rendu/CPE_2015_corewar/asm
##
## Made by bougon_p
## Login   <bougon_p@epitech.net>
##
## Started on  Thu Mar 10 14:59:56 2016 bougon_p
## Last update Mon Mar 14 18:37:51 2016 bougon_p
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
			$(PARSER)create_file.c \
			$(PARSER)convert.c \
			$(LEXER)lexer.c \
			$(LEXER)check_name.c \
			$(LEXER)check_comment.c \
			$(LEXER)check_instructions.c \
			$(LEXER)epure_file.c \
			$(LEXER)put_in_list.c \
			$(LEXER)check_char.c \
			$(LEXER)check_stock.c \
			$(LEXER)verif_args.c \
			$(LEXER)check_good_args.c \
			$(LEXER)my_strcmp.c \
			$(LEXER)my_strcpy.c \
			$(LEXER)my_strncmp.c \
			$(LEXER)my_strncpy.c \
			$(LEXER)print_list.c \
			$(TOOLS)get_next_line.c \
			$(TOOLS)str_null.c \
			$(ERROR)error_stop.c

OBJS    	=	$(SRC:.c=.o)


# LIBRARY VARIABLES

LIBPATH =       ../lib/

SRCLIB	=	$(LIBPATH)my/get_next_line.c \
		$(LIBPATH)my/my_getnbr.c \
		$(LIBPATH)my/my_printf.c \
		$(LIBPATH)my/my_printfcsspb.c \
		$(LIBPATH)my/my_printfdiouxx.c \
		$(LIBPATH)my/my_printfmetc.c \
		$(LIBPATH)my/my_putchar.c \
		$(LIBPATH)my/my_put_nbr.c \
		$(LIBPATH)my/my_putstr.c \
		$(LIBPATH)my/my_revstr.c \
		$(LIBPATH)my/my_strcmp.c \
		$(LIBPATH)my/my_strdup.c \
		$(LIBPATH)my/my_strlen.c \
		$(LIBPATH)my/my_strncmp.c \

LDFLAGS =       -lmy -L$(LIBPATH)

OBJSLIB	=	$(SRCLIB:.c=.o)

# PROJECT VARIABLES

NAME	=	asm

IFLAG	=	-Iinclude/

CFLAGS  =	-W -Wall -Wextra $(IFLAG)

CC      =	gcc -g $(CFLAGS)



# PROJECT RULES

$(NAME)		: 	$(OBJSLIB) $(OBJS)
			@ar rc $(LIBPATH)libmy.a $(OBJSLIB)
			@ranlib $(LIBPATH)libmy.a
			@$(ECHO) "$(GREEN)\n> Compiling project\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"
			@$(CC) -o $(NAME) $(OBJS)

all		:	$(NAME)

clean		:
			@$(RM) $(OBJS)
			@$(RM) $(OBJSLIB)
			@$(ECHO) "$(GREEN)\n> Cleaning repository\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

fclean		: 	clean
			@$(RM) $(NAME)
			@$(RM) $(LIBPATH)/libmy.a
			@$(ECHO) "$(GREEN)\n> Cleaning exec\t\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

re		:	fclean all

.c.o		:
			@$(CC) -c $< -o $@
			@$(ECHO) "$(GREEN)[OK] > $<\t \t $(WHITE)"
