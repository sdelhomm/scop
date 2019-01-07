# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/15 17:57:32 by sdelhomm          #+#    #+#              #
#    Updated: 2018/03/13 16:45:19 by sdelhomm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
parser.c

SRCPATH = ./src/

OBJ = $(SRC:.c=.o)

LIB = libft.a

LIBPATH = ./libft/

NAME = scop

FLAGS = -Wall -Werror -Wextra

all : $(NAME)
$(NAME) :
	@make -C $(LIBPATH)
	@gcc -c $(FLAGS) $(addprefix $(SRCPATH),$(SRC))
	@echo "\033[33;32m[Create objects]\t\t\t[ ✓ ]"
	@gcc -o $(NAME) $(FLAGS) $(OBJ) $(LIBPATH)$(LIB)
	@echo "\033[33;32m[Create $(NAME)]\t\t\t\t[ ✓ ]"

clean :
	@make clean -C $(LIBPATH)
	@rm -f $(OBJ)
	@echo "\033[33;32m[Clean objects]\t\t\t\t[ ✓ ]"

fclean : clean
	@rm -f $(LIBPATH)$(LIB)
	@rm -f $(NAME)
	@echo "\033[33;32m[Clean $(NAME)]\t\t\t\t[ ✓ ]"

re : fclean all
