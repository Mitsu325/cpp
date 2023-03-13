# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 20:03:30 by pmitsuko          #+#    #+#              #
#    Updated: 2023/01/31 19:38:10 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## COLORS ##

DEFAULT		=	\e[39m
GREEN		=	\e[92m
YELLOW		=	\e[93m
MAGENTA		=	\e[95m
CYAN		=	\e[96m

# **************************************************************************** #

NAME = materia

# COMPILATION #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
VAL = valgrind --leak-check=full --show-leak-kinds=all

# DELETE #

RM = rm -rf

# HEADER #

HEADER = AMateria.hpp\
		Ice.hpp\
		Cure.hpp\
		ICharacter.hpp\
		Character.hpp\
		IMateriaSource.hpp\
		MateriaSource.hpp

# FILES #

FILES = main.cpp\
		AMateria.cpp\
		Ice.cpp\
		Cure.cpp\
		Character.cpp\
		MateriaSource.cpp

# COMPILED_SOURCES #

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(FILES:.cpp=.o)))

## RULES ##

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "\n$(CYAN)----------------------------------------"
		@echo "--------------- MAKE EX03 --------------"
		@echo "----------------------------------------\n$(DEFAULT)"

$(OBJ_DIR)%.o: %.cpp $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
		@mkdir $(OBJ_DIR)

clean:
		@$(RM) $(OBJ_DIR)

fclean: clean
		@$(RM) $(NAME)
		@echo "\n$(MAGENTA)----------------------------------------"
		@echo "------------- CLEANING DONE ------------"
		@echo "----------------------------------------\n$(DEFAULT)"

re: fclean all

run: re
		$(VAL) ./$(NAME)

.PHONY: all clean fclean re
