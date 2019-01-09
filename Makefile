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

#Sources files
SRC = main.c \
parser.c \
init.c

#Sources location
SRCPATH = ./src/

OBJ = $(SRC:.c=.o)

#Libraries paths
LIBFT = ./libft/
GLFW = ./glfw/

#Libraries binaries
LIBFTBIN = libft.a

#Libraries includes
GLFW_INC = -I $(GLFW)/include
LIBFT_INC = -I $(LIBFT)/includes

#Libraries linking
GLFW_LINK = -L $(GLFW)/src -l glfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
LIBFT_LINK = -L $(LIBFT) -l ft

#Program name
NAME = scop

#gcc flags
FLAGS = -Wall -Werror -Wextra

all : $(NAME)
$(NAME) :
	@cd $(GLFW) && cmake .
	@make -C $(GLFW) glfw
	@make -C $(LIBFT)
	@gcc -c $(FLAGS) $(GLFW_INC) $(LIBFT_INC) $(addprefix $(SRCPATH),$(SRC))
	@echo "\033[33;32m[Create objects]\t\t\t[ ✓ ]"
	@gcc -o $(NAME) $(FLAGS) $(OBJ) $(GLFW_LINK) $(LIBFT_LINK)
	@echo "\033[33;32m[Create $(NAME)]\t\t\t\t[ ✓ ]"

clean :
	@make -C $(GLFW) clean
	@make -C $(LIBFT) clean
	@rm -f $(OBJ)
	@echo "\033[33;32m[Clean objects]\t\t\t\t[ ✓ ]"

fclean : clean
	@rm -rf $(GLFW)/CMakeCache.txt $(GLFW)/CMakeFiles/
	@rm -f $(LIBFT)$(LIBFTBIN)
	@rm -f $(NAME)
	@echo "\033[33;32m[Clean $(NAME)]\t\t\t\t[ ✓ ]"

re : fclean all

.PHONY : all clean fclean re
