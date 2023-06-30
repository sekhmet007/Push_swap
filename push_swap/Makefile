# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecullier <ecullier@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 16:39:33 by ecullier          #+#    #+#              #
#    Updated: 2023/06/28 15:16:23 by ecullier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PUSHSWAP_SRCS = srcs/*.c
HEADERS = push_swap.h

CC	= gcc -g
CFLAGS	= -Wall -Wextra -Werror

all:    libft push_swap
	@echo "✅ Push_swap compiled\n"

libft:
	@make -s -C libft
	@echo "✅ Libft compiled\n"

push_swap: 
	@$(CC) $(PUSHSWAP_SRCS) libft/libft.a -o $(NAME) $(CFLAGS) -Llibft -lft

srcs/%.o: srcs/%.c ${HEADERS}
	  @$(CC) -c $< -o $@ $(CFLAGS)

%.o: %.c ${HEADERS}
	 @$(CC) $(CFLAGS) libft -c $< -o $@

clean:
	@rm -rf $(PUSHSWAP_SRCS:%.c=%.o)
	@make fclean -s -C libft
	@echo "✅ Push_swap cleaned\n"

fclean: clean
	@echo ✅ "Clean push_swap\n"
	@rm -f $(NAME) 
	@make fclean -s -C libft

re: fclean all
	@echo "✅ Push_swap recompiled\n"

.PHONY: all libft clean fclean re
