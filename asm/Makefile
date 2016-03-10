##
## Makefile for Makefile in /home/mmaud/Rendu/Semestre_2/System_Unix/
##
## Made by Maud MAREL
## Login   <marel_m@epitech.net>
##
## Started on  Sun Jan 31 11:11:37 2016 Maud MAREL
## Last update Thu Mar 10 16:10:56 2016 
##

NAME		=	asm

SRCS		=	srcs/lexer/lexer.c \

OBJS		=	$(SRCS:.c=.o)

CFLAGS		+=	-W -Wall -Wextra

CFLAGS		+=	-Iinclude/

CFLAGS		+=	$(LIBS)

FLAGS		=	$(LDFLAGS)

CC		=	gcc -g

RM		=	rm -f

$(NAME):		$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(FLAGS)

all:			$(NAME)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all
