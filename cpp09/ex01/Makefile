# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 17:16:06 by pmitsuko          #+#    #+#              #
#    Updated: 2023/03/19 18:50:46 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## COLORS ##

DEFAULT		=	\e[39m
GREEN		=	\e[92m
YELLOW		=	\e[93m
MAGENTA		=	\e[95m
CYAN		=	\e[96m

# **************************************************************************** #

NAME = RPN

# COMPILATION #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
VAL = valgrind --leak-check=full --show-leak-kinds=all

# DELETE #

RM = rm -rf

# HEADER #

HEADER = RPN.hpp

# FILES #

FILES = main.cpp\
		RPN.cpp

# COMPILED_SOURCES #

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(FILES:.cpp=.o)))

## RULES ##

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "\n$(CYAN)----------------------------------------"
		@echo "--------------- MAKE EX01 --------------"
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
		$(VAL) ./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"

# $VAR="shuf -i 1-1000000 -r -n 3000 | tr '\n' ' '"
.PHONY: all clean fclean re
