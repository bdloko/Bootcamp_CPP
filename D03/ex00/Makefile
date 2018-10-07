# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdloko <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/08 16:22:30 by bdloko            #+#    #+#              #
#    Updated: 2018/06/08 16:22:33 by bdloko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = frager
FILES = FragTrap.cpp main.cpp
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@clang++ $(FLAGS) $(FILES) -o $(NAME) 

fclean:
	@rm -f $(NAME)

re: fclean all
