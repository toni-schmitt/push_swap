# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/29 21:22:56 by tschmitt          #+#    #+#              #
#    Updated: 2021/09/01 14:31:39 by tschmitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CCFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRC_PATH = ./src/
OBJ_PATH = ./obj/
OPERATIONS_SRC_PATH = $(SRC_PATH)operations
OPERATIONS_OBJ_PATH = $(OBJ_PATH)operations/
INCLUDE_PATH = ./include/
HEADER = $(INCLUDE_PATH)push_swap.h
LIBFT_PATH = ./libs/libft/

NAME = push_swap
LIBFT_NAME = $(LIBFT_PATH)lib/libft.a

SRC = $(SRC_PATH)main.c $(SRC_PATH)parse_input.c $(SRC_PATH)stack.c
OPERATIONS = $(OPERATIONS_SRC_PATH)push.c $(OPERATIONS_SRC_PATH)reverse.c $(OPERATIONS_SRC_PATH)rotate.c $(OPERATIONS_SRC_PATH)swap.c
OBJ = $(patsubst $(OPERATIONS_SRC_PATH)%.c, $(OPERATIONS_OBJ_PATH)%.o, $(OPERATIONS))
OPERATIONS_OBJ = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRC))

INCLUDE_FLAGS = -I $(LIBFT_PATH)include/ -I $(INCLUDE_PATH)

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all: $(NAME) $(LIBFT_NAME)
	@echo $(G)Finished...$(X)

$(LIBFT_NAME):
	@echo $(Y)Compiling [$(LIBFT_NAME)]...$(X)
	@make -C $(LIBFT_PATH)
	@printf $(UP)$(CUT)
	@echo $(G)Finished [$(LIBFT_NAME)]$(X)

$(NAME): $(OBJ) $(OPERATIONS_OBJ) $(LIBFT_NAME)
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CCFLAGS) $(INCLUDE_FLAGS) $(OBJ) $(OPERATIONS_OBJ) $(LIBFT_NAME) -o $(NAME)
	@echo $(G)Finished [$(NAME)]$(X)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER)
	@echo $(Y)Compiling [$@]...$(X)
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OPERATIONS_OBJ_PATH)
	@$(CC) $(CCFLAGS) $(INCLUDE_FLAGS) -o $@ -c $<
	@printf $(UP)$(CUT)
	@echo $(G)Finished [$@]$(X)
	@printf $(UP)$(CUT)

clean:
	@make -C $(LIBFT_PATH) clean
	@$(RM) -r $(OBJ_PATH)
	@echo $(R)Cleaning"  "[$(OBJ) $(OPERATIONS_OBJ)]...$(X)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@echo $(R)Cleaning"  "[$(NAME)]...$(X)

re: fclean all

.PHONY: all, clean, fcelan, re