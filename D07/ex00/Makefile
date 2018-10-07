# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdloko <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/14 13:31:11 by bdloko            #+#    #+#              #
#    Updated: 2018/06/14 13:31:14 by bdloko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = whatever
FILES = main.cpp whatever.cpp
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	    @clang++ $(FLAGS) $(FILES) -o $(NAME) 

fclean:
	    @rm -f $(NAME)

re: fclean all
