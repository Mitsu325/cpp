# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 08:34:25 by pmitsuko          #+#    #+#              #
#    Updated: 2023/02/04 11:27:24 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## COLORS ##

DEFAULT		=	\e[39m
GREEN		=	\e[92m
YELLOW		=	\e[93m
MAGENTA		=	\e[95m
CYAN		=	\e[96m

# **************************************************************************** #

NAME = bureaucrat

# COMPILATION #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
VAL = valgrind --leak-check=full --show-leak-kinds=all

# DELETE #

RM = rm -rf

# HEADER #

HEADER = Bureaucrat.hpp\
		AForm.hpp\
		ShrubberyCreationForm.hpp\
		RobotomyRequestForm.hpp\
		PresidentialPardonForm.hpp

# FILES #

FILES = main.cpp\
		Bureaucrat.cpp\
		AForm.cpp\
		ShrubberyCreationForm.cpp\
		RobotomyRequestForm.cpp\
		PresidentialPardonForm.cpp

# COMPILED_SOURCES #

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(FILES:.cpp=.o)))

## RULES ##

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
		@echo "\n$(CYAN)----------------------------------------"
		@echo "--------------- MAKE EX02 --------------"
		@echo "----------------------------------------\n$(DEFAULT)"
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

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
