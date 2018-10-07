# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdloko <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/08 16:24:12 by bdloko            #+#    #+#              #
#    Updated: 2018/06/08 16:36:16 by bdloko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scaver
FILES = FragTrap.cpp ScavTrap.cpp main.cpp
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@clang++ $(FLAGS) $(FILES) -o $(NAME) 

fclean:
	@rm -f $(NAME)

re: fclean all
