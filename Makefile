# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 11:40:15 by fkhan             #+#    #+#              #
#    Updated: 2022/03/16 17:32:42 by fkhan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= push_swap.a
LIBFTPRINTF		= libftprintf.a
PRINTFPATH		= lib
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
LIB 			= ar -rcs
RM				= rm -f

SRCS 			= push_swap.c push_swap_utils.c quick_sort.c sort_stack.c \
				  push_swap_stack.c sort_stack_utils.c sort_big_stack.c \
				  debug.c

OBJS 			= $(SRCS:.c=.o)

$(NAME): 		$(OBJS)
				make -C $(PRINTFPATH)
				cp $(PRINTFPATH)/$(LIBFTPRINTF) .
				mv $(LIBFTPRINTF) $(NAME)
				$(LIB) $(NAME) $(OBJS)

%.o: 			%.c
				$(CC) $(CFLAGS) -c $< -o $@		

all: 			$(NAME)

bonus:			all

clean:	 		
				$(RM) $(OBJS)
				make clean -C $(PRINTFPATH)

fclean: 		clean
				$(RM) $(NAME)
				$(RM) $(PRINTFPATH)/$(LIBFTPRINTF)

re: 			fclean all

.PHONY: 		all bonus clean fclean re