# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvilla <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/22 20:11:16 by bvilla            #+#    #+#              #
#    Updated: 2019/02/19 21:05:27 by bvilla           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SOURCE = main.c check.c
INC = .
OBJS = $(SOURCE:%.c=%.o)

$(NAME):
	@make re -C libft/ 
	@gcc -c $(SOURCE) -I. -I libft/
	@gcc $(OBJS) -Wall -Wextra -Werror libft/libft.a -o $(NAME)
	@echo "compilation complete"
all: $(NAME)
clean:
	@rm -f $(OBJS)
	@make clean -C libft/
	@echo "removed objects"
fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/
	@echo "removed binary and libraries"
re: fclean all 
