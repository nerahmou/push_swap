# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nerahmou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:17:07 by nerahmou          #+#    #+#              #
#    Updated: 2018/03/21 14:27:00 by nerahmou    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean
.SUFFIXES:

FLAGS= yes
NAME = checker
CC = gcc
NAME_2 = push_swap
DEBUG = yes

ifeq ($(FLAGS), yes)
	CFLAGS = -Wall -Wextra -Werror
endif

ifeq ($(DEBUG), yes)
	CFLAGS += -g
endif

INC_PATH = ./include
SRC_PATH = ./srcs
OBJ_PATH = ./obj

SRC_NAME =	checker.c\
			set_queue.c\
			parse_param.c\
			check_operations.c\
			operations.c\
			get_elem_and_check_sort.c

SRC_PUSH_NAME =push_swap.c\
			set_queue.c\
			parse_param.c\
			check_operations.c\
			operations.c\
			get_elem_and_check_sort.c\
			easy_sort.c\
			easy_sort_b.c


INC_NAME = push_swap.h
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PUSH_NAME = $(SRC_PUSH_NAME:.c=.o)

INC = $(addprefix $(INC_PATH)/,$(INC_NAME))
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
SRC_PUSH = $(addprefix $(SRC_PATH)/,$(SRC_PUSH_NAME))
OBJ_PUSH = $(addprefix $(OBJ_PATH)/,$(OBJ_PUSH_NAME))

all: $(NAME) $(NAME_2)

$(NAME): $(OBJ) $(INC)
	@make -C libft
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ) -I $(INC) -L./libft -lft
	@echo "checker created 👍 \n"
	
$(NAME_2): $(OBJ_PUSH) $(INC)
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ_PUSH) -I $(INC) -L./libft -lft

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -rf $(OBJ_PATH)
	
fclean: clean
	@make -C libft fclean
	@rm -f $(NAME) $(NAME_2)

re: fclean all
