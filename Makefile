# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edforte <edforte@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 11:55:41 by edforte           #+#    #+#              #
#    Updated: 2024/07/11 15:53:00 by edforte          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = \
			main.c \
			main_utils.c \
			main_utils2.c \
			main_utils3.c \
			push_swap.c \
			psh_swp_fts.c \
			push_swap_utils.c \
			push_swap_utils2.c \
			input_check.c \
			input_check_utils.c \
			ft_split.c \
			rules.c \
			tiny_sort.c \
			tiny_sort_utils.c \


OBJ = $(CFILES:.c=.o)


CC = @ gcc
FLAGS = -g -Wall -Wextra -Werror
RM = rm -rf

NAME = push_swap

name : $(NAME)

all : $(NAME)

$(NAME) : $(OBJ)
	 $(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean :
	@ $(RM) $(OBJ)

fclean : clean
	@ $(RM) $(NAME)

re : fclean all
