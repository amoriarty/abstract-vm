# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alegent <alegent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/13 12:17:39 by alegent           #+#    #+#              #
#    Updated: 2016/05/11 16:48:56 by alegent          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= avm

SRC_PATH= srcs/
SRC_NAME= main.cpp \
		  class/Calculator.cpp \
		  class/Exceptions.cpp \
		  class/Factory.cpp \
		  class/Parser.cpp

SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_PATH= obj/
OBJ_NAME= $(SRC_NAME:.cpp=.o)
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))

GCC= clang++ -Wall -Wextra -Werror

INC = -I include/ \
	  -I include/class \
	  -I include/interface \
	  -I include/template

all: $(NAME)

$(NAME): $(OBJ)
	@$(GCC) $(INC) -o $(NAME) $(OBJ)
	@echo "Your program is ready to go !"

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir -p obj/class
	$(GCC) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)
	@echo "Object files has been deleted"

fclean: clean
	@rm -rf $(NAME)
	@echo "Program has been deleted"

re: fclean all

.PHONY: clean fclean re

