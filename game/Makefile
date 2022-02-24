# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 17:31:43 by llonnrot          #+#    #+#              #
#    Updated: 2022/02/24 23:33:35 by linuxlite        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = termindle

CFILES = prog.c
FLAGS = -Wall -Wextra -Werror
INCL = -I ../libft/
LIB = -L ../libft -lft

all: $(NAME)

$(NAME):
	make -C ../libft re
	gcc $(FLAGS) $(INCL) $(CFILES) $(LIB) -o $(NAME)

clean:
	make -C ../libft clean
	/bin/rm -f *.o
	
fclean: clean
	make -C ../libft fclean
	/bin/rm -f $(NAME)
re: fclean all