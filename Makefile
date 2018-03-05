# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nerahmou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:17:07 by nerahmou          #+#    #+#              #
#    Updated: 2018/03/05 15:15:22 by nerahmou    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean
.SUFFIXES:

FLAGS= no
NAME = checker
CC = gcc

ifeq ($(FLAGS), yes)
	CFLAGS = -Wall -Wextra -Werror
endif

SRC_PATH = ./srcs
OBJ_PATH = ./obj
INC_PATH = ./include

SRC_NAME =	main.c\
			set_queue.c\
			parse_param.c\
			push_swap.c
INC_NAME = push_swap.h
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@make -C libft
	@$(CC) $(CFLAGS) -o $@ $(OBJ) -I $(INC_PATH) -L./libft -lft
	@echo "checker created 👍 \n"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -rf $(OBJ_PATH)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all
