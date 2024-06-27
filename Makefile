
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 05:41:09 by afalconi          #+#    #+#              #
#    Updated: 2023/06/19 11:59:05 by afalconi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFILES = \
			input_check.c \
			push_rule.c \
			push_swap.c \
			push_swap_utils.c \
			reverse_rotate.c \
			rotate_rule.c \
			swap_rule.c \


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
