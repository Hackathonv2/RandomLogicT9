##
## EPITECH PROJECT, 2023
## B-PSU-100-BDX-1-1-myls-tom.seng
## File description:
## Makefile
##

CC = gcc

CFLAGS = -Wall -Wextra -std=c99

LIBS = 

SRC = ex1.c	\

OBJ = $(SRC:.c = .o)

NAME = ex1

all : $(NAME)

re : clean all

$(NAME): $(OBJ)
	$(CC) -g $(LIBS) $(CFLAGS) -o $(NAME) $(SRC)

clean :
	rm -f $(NAME)
