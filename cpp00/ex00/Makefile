# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 08:15:56 by pmitsuko          #+#    #+#              #
#    Updated: 2022/11/23 08:43:20 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## COLORS ##

DEFAULT		=	\e[39m
GREEN		=	\e[92m
YELLOW		=	\e[93m
MAGENTA		=	\e[95m
CYAN		=	\e[96m

# **************************************************************************** #

NAME = megaphone

# COMPILATION #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# DELETE #

RM = rm -rf

# FILES #

FILES = megaphone.cpp


# COMPILED_SOURCES #

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(FILES:.cpp=.o)))

## RULES ##

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
		@echo "\n$(CYAN)----------------------------------------"
		@echo "--------------- MAKE EX00 --------------"
		@echo "----------------------------------------\n$(DEFAULT)"
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
		mkdir $(OBJ_DIR)

clean:
		$(RM) $(OBJ_DIR)

fclean: clean
		$(RM) $(NAME)
		@echo "\n$(MAGENTA)----------------------------------------"
		@echo "------------- CLEANING DONE ------------"
		@echo "----------------------------------------\n$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re
