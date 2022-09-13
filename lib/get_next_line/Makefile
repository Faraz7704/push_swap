# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 18:06:55 by faraz             #+#    #+#              #
#    Updated: 2022/09/13 23:25:57 by fkhan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				= libgnl.a
CC 					= gcc
FLAGS 				= -Wall -Werror -Wextra
LIB					= ar -rcs
INCLUDES 			= -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)

LIB_DIRECTORY 		= ../

LIBFT 				= $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY 	= $(LIB_DIRECTORY)libft/
LIBFT_HEADERS 		= $(LIBFT_DIRECTORY)includes/

HEADERS_DIRECTORY 	= ./includes/
HEADERS_LIST 		= get_next_line.h
HEADERS 			= $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY 	= ./sources/
SOURCES_LIST 		= get_next_line.c utils.c
SOURCES 			= $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY 	= ./objects/
OBJECTS_LIST 		= $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS				= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS
GREEN 				= \033[0;32m
RED					= \033[0;31m
RESET 				= \033[0m

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@cp $(LIBFT) .
	@mv libft.a $(NAME) 
	@$(LIB) $(NAME) $(OBJECTS)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo ".\c"

clean:
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re
