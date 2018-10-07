# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdloko <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/13 14:50:51 by bdloko            #+#    #+#              #
#    Updated: 2018/06/13 14:50:53 by bdloko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serial
FILES = main.cpp
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@clang++ $(FLAGS) $(FILES) -o $(NAME) 

fclean:
	@rm -f $(NAME)

re: fclean all
