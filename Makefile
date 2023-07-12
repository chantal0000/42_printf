# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 10:34:54 by chbuerge          #+#    #+#              #
#    Updated: 2023/07/05 11:02:09 by chbuerge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 		libftprintf.a
LIBFT_NAME = libft.a

CC		 		= 	cc
CFLAGS		 	=		-Wall -Wextra -Werror
LIBFT_DIR = ./libft


SRCS	 = 		ft_printf.c \
				ft_printf_utils.c

OBJS	 = ${SRCS:.c=.o}


all:		${NAME}

#build the libft
makelibft:
		@make -C $(LIBFT_DIR)
		@cp $(LIBFT_DIR)/$(LIBFT_NAME) .
		@mv $(LIBFT_NAME) $(NAME)

${NAME}:	makelibft ${OBJS}
					ar rcs ${NAME} ${OBJS}

# Remove object files and executables
clean:
	rm -f ${OBJS}
	@cd $(LIBFT_DIR) && make clean

# Remove object files, executables, and the libft library
fclean:	clean
	rm -f ${NAME}
	cd $(LIBFT_DIR) && make fclean

# Rebuild the project from scratch
re:	fclean all



.PHONY: all clean fclean re

