# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmucassi <lmucassi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/10 11:45:14 by lmucassi          #+#    #+#              #
#    Updated: 2018/06/17 18:19:42 by bdloko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm
FILES = SRC/main.cpp				\
		SRC/CurseWindow.cpp			\
		SRC/CurrentModule.cpp		\
		SRC/timedateModule.cpp 		\
		SRC/HostnameModule.cpp 		\
		SRC/NetworkModule.cpp 		\
		SRC/osModule.cpp			\
		SRC/HardwareSoftware.cpp
		
FLAGS = -Wall -Werror -Wextra -lncurses -lpthread

all: $(NAME)

$(NAME): 
	@echo	"\033[32mCreating \t: \tGKRELLM PROJECT \033[00m"
	@echo	"\033[32mAUTHORS \t: \tBDLOKO & LMUCASSI \033[00m"
	@echo	"\033[32mPROJECT \t: \tRUSH \033[00m"
	@echo	"\033[32mRUSH NO \t: \t01  \033[00m"
	@echo	"\033[32mPISCINE \t: \tCPP BOOTCAMP \033[00m"
	@echo	"\033[32mSCHOOL	\t: \tWETHINKCODE_ [JHB] \033[00m"
	@clang++ $(FLAGS) $(FILES) -o $(NAME) 
	@echo	"\033[32mFinishing Compilation \033[00m"
	@echo	"\033[32mDONE ! \033[00m"

clean:
	@echo	"\033[32mCleaning Project \033[00m"
	@rm	 $(NAME)
	@echo	"\033[32mDONE ! \033[00m"

fclean: clean

re:	fclean all

.PHONY: re clean fclean
