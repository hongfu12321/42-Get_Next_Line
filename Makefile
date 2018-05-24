# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhong <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/23 14:54:59 by fhong             #+#    #+#              #
#    Updated: 2018/05/23 15:01:12 by fhong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
W = -Wall -Wextra -Werror
SRC = *.c
OBJ = *.h

all: $(NAME)
$(NAME):
	make -C libft
	gcc -o $(NAME) $(W) $(SRC) -Llibfr -lft -I fillit.h

clean:
	make clean -C libft
	/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)

re: fclean all
