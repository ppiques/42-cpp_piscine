# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 15:52:20 by ppiques           #+#    #+#              #
#    Updated: 2022/08/02 15:52:20 by ppiques          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= convert

RM			= rm -f
RD			= rm -fr

FILE_DIR	= srcs
INC_DIR		= includes
OBJ_DIR		= .objs

FILE_NAMES	+= main.cpp
FILE_NAMES	+= scalar.cpp
FILE_NAMES	+= utils.cpp

OBJ_NAMES	= ${FILE_NAMES:.cpp=.o}
OBJS		= $(addprefix $(OBJ_DIR)/, $(OBJ_NAMES))

CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98

all:		${NAME}

$(NAME):	${OBJS}
			@echo "\033[1;34mCompiling $(NAME)...\033[0m"
			@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
			@echo "\n\033[1;93mAll done !\033[0m\n"

$(OBJ_DIR)/%.o :	$(FILE_DIR)/%.cpp ${INC_DIR}/*.hpp | $(OBJ_DIR)
					@echo "\033[0;96mCompiling $<\033[0m"
					@$(CXX) $(CXXFLAGS) -c $< -o $@ -I./$(INC_DIR)/

$(OBJ_DIR) :
				@mkdir -p $(OBJ_DIR)

clean:
			@echo "\033[0;31mDeleting objects ...\033[0m\n"
			@${RM} ${OBJS}
			@$(RD) $(OBJ_DIR)
			@echo "\033[0;31mDone.\033[0m\n"

fclean:		clean
			@echo "\033[0;31mDeleting libraries and executable\033[0m"
			@${RM} ${NAME}
			@echo "\033[0;31mDone.\033[0m\n"

re:			fclean all

.PHONY: 	all clean fclean re