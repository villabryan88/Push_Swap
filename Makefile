# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvilla <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/22 20:11:16 by bvilla            #+#    #+#              #
#    Updated: 2019/03/04 19:44:35 by bvilla           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SOURCE = check.c parser.c operations.c stack.c stack2.c queue.c
INC = .
OBJS = $(SOURCE:%.c=%.o)

$(NAME):
	@make re -C libft/ 
	@gcc -g -c $(SOURCE) push_swap.c checker.c -I. -I libft/
	@gcc -g $(OBJS) push_swap.o -Wall -Wextra -Werror libft/libft.a -o push_swap
	@gcc  -g $(OBJS) checker.o -Wall -Wextra -Werror libft/libft.a -o checker
	@echo "compilation complete"
all: $(NAME)
clean:
	@rm -f $(OBJS) push_swap.o checker.o
	@make clean -C libft/
	@echo "removed objects"
fclean: clean
	@rm -f push_swap
	@rm -f checker
	@make fclean -C libft/
	@echo "removed binary and libraries"
re: fclean all 