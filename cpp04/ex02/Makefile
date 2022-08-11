# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 14:16:28 by ppiques           #+#    #+#              #
#    Updated: 2022/08/11 14:16:28 by ppiques          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ideas

RM			= rm -f
RD			= rm -fr

FILE_DIR	= srcs
INC_DIR		= includes
OBJ_DIR		= .objs

FILE_NAMES	+= main.cpp
FILE_NAMES	+= animal.cpp
FILE_NAMES	+= brain.cpp
FILE_NAMES	+= cat.cpp
FILE_NAMES	+= dog.cpp
FILE_NAMES	+= wrongAnimal.cpp
FILE_NAMES	+= wrongCat.cpp

OBJ_NAMES	= ${FILE_NAMES:.cpp=.o}
OBJS		= $(addprefix $(OBJ_DIR)/, $(OBJ_NAMES))

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

all:		${NAME}

$(NAME):	${OBJS}
			@echo "\033[1;34mCompiling $(NAME)...\033[0m"
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "\n\033[1;93mAll done !\033[0m\n"

$(OBJ_DIR)/%.o :	$(FILE_DIR)/%.cpp ${INC_DIR}/*.hpp | $(OBJ_DIR)
					@echo "\033[0;96mCompiling $<\033[0m"
					@$(CC) $(CFLAGS) -c $< -o $@ -I./$(INC_DIR)/

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