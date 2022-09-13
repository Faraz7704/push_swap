# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 11:40:15 by fkhan             #+#    #+#              #
#    Updated: 2022/09/13 23:26:28 by fkhan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				= push_swap
BONUS 				= checker
CC 					= gcc
FLAGS 				= -Wall -Werror -Wextra
INCLUDES 			= -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) \
						-I$(FT_PRINTF_HEADERS) -I$(GNL_HEADERS)
LIBRARIES 			= -lft -lft_printf -lgnl \
						-L$(LIBFT_DIRECTORY) -L$(FT_PRINTF_DIRECTORY) \
						-L$(GNL_DIRECTORY)

LIB_DIRECTORY 		= ./lib/

LIBFT 				= $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY 	= $(LIB_DIRECTORY)libft/
LIBFT_HEADERS 		= $(LIBFT_DIRECTORY)includes/

FT_PRINTF			= $(FT_PRINTF_DIRECTORY)libft_printf.a
FT_PRINTF_DIRECTORY = $(LIB_DIRECTORY)ft_printf/
FT_PRINTF_HEADERS 	= $(FT_PRINTF_DIRECTORY)includes/

GNL 				= $(GNL_DIRECTORY)libgnl.a
GNL_DIRECTORY 	= $(LIB_DIRECTORY)get_next_line/
GNL_HEADERS 		= $(GNL_DIRECTORY)includes/

HEADERS_DIRECTORY 	= ./includes/
HEADERS_LIST 		= push_swap.h
HEADERS 			= $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY 	= ./sources/
SOURCES_LIST 		= main.c utils.c arg.c arg_utils.c list_utils.c \
						stack.c \
						stack_inst.c stack_inst_combine.c stack_inst_utlis.c \
						stack_set.c stack_set_utils.c stack_set_utils2.c \
						stack_divide_conquer.c stack_divide_conquer_utils.c \
						stack_insertsort_a.c stack_insertsort_b.c \
						quick_sort.c quick_sort_utils.c \
						stack_sort.c stack_sort_utils.c \
						stack_bigsort.c \
						debug.c
SOURCES 			= $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY 	= objects/
OBJECTS_LIST 		= $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS				= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

BSOURCES_LIST 		= checker.c utils.c arg.c arg_utils.c list_utils.c \
						stack.c \
						stack_inst.c stack_inst_combine.c stack_inst_utlis.c \
						stack_set.c stack_set_utils.c stack_set_utils2.c \
						quick_sort.c quick_sort_utils.c \
						stack_sort_utils.c \
						debug.c
BSOURCES 			= $(addprefix $(SOURCES_DIRECTORY), $(BSOURCES_LIST))

BOBJECTS_LIST 		= $(patsubst %.c, %.o, $(BSOURCES_LIST))
BOBJECTS			= $(addprefix $(OBJECTS_DIRECTORY), $(BOBJECTS_LIST))

# COLORS
GREEN 				= \033[0;32m
RED 				= \033[0;31m
RESET 				= \033[0m

all: $(NAME) $(BONUS)

bonus: $(BONUS)

$(BONUS) : $(LIBFT) $(FT_PRINTF) $(GNL) $(OBJECTS_DIRECTORY) $(BOBJECTS)
	@$(CC) $(FLAGS) $(BOBJECTS) $(LIBRARIES) $(INCLUDES) -o $(BONUS)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(BONUS) was created$(RESET)"

$(NAME): $(LIBFT) $(FT_PRINTF) $(GNL) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(OBJECTS) $(LIBRARIES) $(INCLUDES) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo ".\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(FT_PRINTF):
	@echo "$(NAME): $(GREEN)Creating $(FT_PRINTF)...$(RESET)"
	@$(MAKE) -sC $(FT_PRINTF_DIRECTORY)

$(GNL):
	@echo "$(NAME): $(GREEN)Creating $(GNL)...$(RESET)"
	@$(MAKE) -sC $(GNL_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@$(MAKE) -sC $(FT_PRINTF_DIRECTORY) clean
	@$(MAKE) -sC $(GNL_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(GNL)
	@echo "$(NAME): $(RED)$(GNL) was deleted$(RESET)"
	@rm -f $(FT_PRINTF)
	@echo "$(NAME): $(RED)$(FT_PRINTF) was deleted$(RESET)"
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	@rm -f $(BONUS)
	@echo "$(NAME): $(RED)$(BONUS) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all bonus clean fclean re