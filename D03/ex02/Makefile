# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdloko <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/08 17:38:13 by bdloko            #+#    #+#              #
#    Updated: 2018/06/08 17:38:21 by bdloko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = clapper
FILES = FragTrap.cpp ScavTrap.cpp ClapTrap.cpp main.cpp
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@clang++ $(FLAGS) $(FILES) -o $(NAME) 

fclean:
	@rm -f $(NAME)

re: fclean all
