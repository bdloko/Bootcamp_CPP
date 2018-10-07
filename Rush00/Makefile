CPP = clang++

FLAGS = -Wall -Wextra -Werror

NAME = ft_retro

SRCS = player.cpp \
	   Enemy.cpp \
	   map.cpp \
	   main.cpp \
	   bullet.cpp

HEADERS = player.hpp \
		  enemy.hpp \
		  map.hpp \
		  bullet.hpp

EXTRAS = player.hpp.gch \
		 enemy.hpp.gch \
		 map.hpp.gch \
		 bullet.hpp.gch 

OBJ = player.o \
      map.o \
	  main.o \
	  enemy.o \
	  bullet.o

all : $(NAME);

$(NAME):
	@$(CPP) $(FLAGS) -c $(SRCS) $(HEADER)
	@$(CPP) $(FLAGS) -lncurses $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ) $(EXTRAS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
