# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhong <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/23 14:54:59 by fhong             #+#    #+#              #
#    Updated: 2018/05/25 16:40:14 by fhong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
W = -Wall -Wextra -Werror
SRC = *.c
OBJ = *.o

all: $(NAME)
$(NAME):
	make -C libft
	gcc -o $(NAME) $(W) $(SRC) -Llibft -lft -I get_next_line.h

clean:
	make clean -C libft
	/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)

re: fclean all
