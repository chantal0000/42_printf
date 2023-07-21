# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 10:34:54 by chbuerge          #+#    #+#              #
#    Updated: 2023/07/20 14:16:42 by chbuerge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
# defines name of the output library file
NAME			= 		libftprintf.a
# defines name of the library file of libft project
LIBFT_NAME = libft.a

# which c compiler to use -> cc
CC		 		= 	cc
# which flags to use for warnings and treating warnings
# as errors to make the code safer and stricter
CFLAGS		 	=		-Wall -Wextra -Werror
# the directory where libft is located
LIBFT_DIR = ./libft

# list the source files required to build the libftprintf library
SRCS	 = 		ft_printf.c \
				ft_printf_utils.c \
				ft_print_hex.c \
				ft_unsigned.c
# defines the object files that will be generated fro the source files
## derived from SRCS replacing .c with .o extension for each source file
OBJS	 = ${SRCS:.c=.o}

# BUILD TARGETS
# all -> default target that gets executed when you run make,
# will build the 'libftprintf.a' library
all:		${NAME}

#build the 'libft.a' library
makelibft:
# -C allows you to change directories before running make process
# enter libft directory and run the make process there
		@make -C $(LIBFT_DIR)
# cp -> copies 'libft.a' into the current diectory '.'
		@cp $(LIBFT_DIR)/$(LIBFT_NAME) .
# rename the libft.a to libftprintf.a
		@mv $(LIBFT_NAME) $(NAME)
# compiles the object files into the libftprintf.a static library (ar, archive)
${NAME}:	makelibft ${OBJS}
					@ar -r ${NAME} ${OBJS}

# Remove object files and executables
clean:
	@rm -f ${OBJS}
	@cd $(LIBFT_DIR) && make clean

# Remove object files, executables, and the libft library
fclean:	clean
	@rm -f ${NAME}
	@cd $(LIBFT_DIR) && make fclean

# Rebuild the project from scratch
re:	fclean all



.PHONY: all clean fclean re libft

