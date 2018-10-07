# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdloko <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/14 13:30:14 by bdloko            #+#    #+#              #
#    Updated: 2018/06/14 13:30:18 by bdloko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = iter
FILES = main.cpp iter.cpp
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	    @clang++ $(FLAGS) $(FILES) -o $(NAME)

fclean:
	    @rm -f $(NAME)

re: fclean all
