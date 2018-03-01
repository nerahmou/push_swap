# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nerahmou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:17:07 by nerahmou          #+#    #+#              #
#    Updated: 2018/01/23 11:43:10 by nerahmou    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean
.SUFFIXES:

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_memchr.c \
	  ft_putstr.c \
	  ft_strjoin.c \
	  ft_strsplit.c \
	  ft_memcmp.c \
	  ft_putstr_fd.c \
	  ft_strlcat.c \
	  ft_strstr.c \
	  ft_atoi.c \
	  ft_memcpy.c \
	  ft_strcat.c \
	  ft_strlen.c \
	  ft_strsub.c \
	  ft_bzero.c \
	  ft_memdel.c \
	  ft_strchr.c \
	  ft_strmap.c \
	  ft_strtrim.c\
	  ft_isalnum.c \
	  ft_memmove.c \
	  ft_strclr.c \
	  ft_strmapi.c \
	  ft_tolower.c \
	  ft_isalpha.c \
	  ft_memset.c \
	  ft_strcmp.c \
	  ft_strncat.c \
	  ft_toupper.c\
	  ft_isascii.c \
	  ft_putchar.c \
	  ft_putwstr.c \
	  ft_strcpy.c \
	  ft_strncmp.c \
	  ft_isdigit.c \
	  ft_putchar_fd.c \
	  ft_strdel.c \
	  ft_strncpy.c\
	  ft_isprint.c \
	  ft_putendl.c \
	  ft_strdup.c \
	  ft_strnequ.c \
	  ft_itoa.c \
	  ft_putendl_fd.c \
	  ft_strequ.c \
	  ft_strnew.c \
	  ft_memalloc.c \
	  ft_putnbr.c \
	  ft_putnbrendl.c\
	  ft_striter.c \
	  ft_strnstr.c \
	  ft_memccpy.c \
	  ft_putnbr_fd.c \
	  ft_striteri.c \
	  ft_strrchr.c \
	  ft_lstadd.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstiter.c\
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_swap.c \
	  ft_list_size.c \
	  ft_foreach.c \
	  ft_sqrt.c \
	  ft_lstdisplay_str.c \
	  ft_lstpushback_str.c \
	  ft_lstclear.c \
	  ft_char_pos.c \
	  ft_abs.c \
	  ft_intlen.c \
	  ft_itoa_base_upp.c \
	  ft_itoa_base_low.c \
	  ft_putnbr_base.c\
	  get_next_line.c\
	  ft_putwstr.c \
	  ft_putwchar.c \
	  ft_putnbr_base.c \
	  ft_wstrlen.c \
	  ft_wcharlen.c 

OBJ_PATH = ./tmp
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo	"Library created 👍 \n"

$(OBJ_PATH)/%.o: %.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -rf $(OBJ_PATH)
	@echo	"Clean libft O.K.\n"

fclean: clean
	@rm -rf $(NAME)
	@echo	"Fclean libft O.K.\n"

re: fclean all
