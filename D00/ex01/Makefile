# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdloko <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/05 15:28:09 by bdloko            #+#    #+#              #
#    Updated: 2018/06/05 17:19:20 by bdloko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = diary
FILES = details.cpp contact.class.cpp
OBJECTS = $(FILES:.cpp=.o)
HEADER = details.hpp
FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@clang++ $(FLAGS) -c $(FILES)
	@clang++ $(FLAGS) -o $(NAME) $(OBJECTS)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean
