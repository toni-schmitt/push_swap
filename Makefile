# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/29 21:22:56 by tschmitt          #+#    #+#              #
#    Updated: 2021/08/29 21:31:49 by tschmitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CCFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INCLUDE_PATH = ./include/
LIBFT_PATH = ./libs/libft/

NAME = push_swap
LIBFT_NAME = $(LIBFT_PATH)lib/libft.a

SRC = $(SRC_PATH)main.c
OBJ = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRC))

INCLUDE_FLAGS = -I $(LIBFT_PATH)include/ -I $(INCLUDE_PATH)

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all: $(NAME)
	@echo $(G)Finished...$(X)

$(LIBFT_NAME):
	@echo $(Y)Compiling [$(LIBFT_NAME)]...$(X)
	@make -C $(LIBFT_PATH)
	@printf $(UP)$(CUT)
	@echo $(G)Finished [$(LIBFT_NAME)]$(X)

$(NAME): $(OBJ) $(LIBFT_NAME)
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CCFLAGS) $(INCLUDE_FLAGS) $(OBJ) $(LIBFT_NAME) -o $(NAME)
	@echo $(G)Finished [$(NAME)]$(X)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo $(Y)Compiling [$@]...$(X)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CCFLAGS) $(INCLUDE_FLAGS) -o $@ -c $<
	@printf $(UP)$(CUT)
	@echo $(G)Finished [$@]$(X)
	@printf $(UP)$(CUT)

clean:
	@make -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ)
	@echo $(R)Cleaning"  "[$(OBJ)]...$(X)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@echo $(R)Cleaning"  "[$(NAME)]...$(X)

re: fclean all

.PHONY: all, clean, fcelan, re