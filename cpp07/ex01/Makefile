# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 21:50:49 by pmitsuko          #+#    #+#              #
#    Updated: 2023/02/13 21:09:36 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## COLORS ##

DEFAULT		=	\e[39m
GREEN		=	\e[92m
YELLOW		=	\e[93m
MAGENTA		=	\e[95m
CYAN		=	\e[96m

# **************************************************************************** #

NAME = ex01

# COMPILATION #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# DELETE #

RM = rm -rf

# HEADER #

HEADER = iter.hpp

# FILES #

FILES = main.cpp

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

.PHONY: all clean fclean re
