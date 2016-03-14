##
## Makefile for corewar
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Mon Mar 14 10:57:11 2016 marc brout
## Last update Mon Mar 14 11:35:18 2016 marc brout
##

SRCP	= ./

SRC     = $(SRCP)dasm.c \

OBJS    = $(SRC:.c=.o)

NAME    = dasm

CC      = gcc -g

CFLAGS  =  -W -Wall -Werror

HDFLAGS = -I../include/

LDFLAGS = -lmy -L../lib

RM      = rm -f

.c.o:
	$(CC) -c $< -o $@ $(HDFLAGS) $(CFLAGS)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all: $(NAME) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
