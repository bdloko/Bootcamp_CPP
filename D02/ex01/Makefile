# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdloko <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/07 18:24:01 by bdloko            #+#    #+#              #
#    Updated: 2018/06/07 18:25:29 by bdloko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed
FILES = main.cpp Fixed.cpp
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@clang++ $(FLAGS) $(FILES) -o $(NAME) 

fclean:
	@rm -f $(NAME)

re: fclean all
