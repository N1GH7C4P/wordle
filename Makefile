# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 16:12:22 by linuxlite         #+#    #+#              #
#    Updated: 2022/02/24 16:23:38 by linuxlite        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wordle
CFILES = wordle.c output.c scoring.c dictionary.c alphabet.c
FLAGS = -Wall -Wextra -Werror
INCL = -I ./libft/
LIB = -L ./libft -lft

all: $(NAME)

$(NAME):
	make -C ./libft re
	gcc $(FLAGS) $(INCL) $(CFILES) $(LIB) -o $(NAME)

clean:
	make -C ./libft clean
	/bin/rm -f *.o
	
fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME)
re: fclean all