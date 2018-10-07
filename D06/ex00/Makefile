# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdloko <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/13 14:51:05 by bdloko            #+#    #+#              #
#    Updated: 2018/06/13 14:51:18 by bdloko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert
FILES = main.cpp
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@clang++ $(FLAGS) $(FILES) -o $(NAME) 

fclean:
	@rm -f $(NAME)

re: fclean all
