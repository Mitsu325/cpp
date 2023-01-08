# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/08 17:04:11 by pmitsuko          #+#    #+#              #
#    Updated: 2023/01/08 17:05:18 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## COLORS ##

DEFAULT		=	\e[39m
GREEN		=	\e[92m
YELLOW		=	\e[93m
MAGENTA		=	\e[95m
CYAN		=	\e[96m

# **************************************************************************** #

NAME = brain

# COMPILATION #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# DELETE #

RM = rm -rf

# FILES #

FILES = main.cpp


# COMPILED_SOURCES #

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(FILES:.cpp=.o)))

## RULES ##

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
		@echo "\n$(CYAN)----------------------------------------"
		@echo "--------------- MAKE EX02 --------------"
		@echo "----------------------------------------\n$(DEFAULT)"
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp
		@$(CC) $(CFLAGS) -c $< -o $@

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
