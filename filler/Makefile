# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/31 10:23:18 by fledwaba          #+#    #+#              #
#    Updated: 2018/08/31 14:58:23 by fledwaba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

all:
	make -C ./libft
	gcc -Wall -Wextra -Werror *.c -o $(NAME) libft/libft.a

clean:
	make clean -C ./libft

fclean: clean
	make fclean -C ./libft

re: fclean all
	make re -C ./libft
