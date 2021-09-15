# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/29 21:22:56 by tschmitt          #+#    #+#              #
#    Updated: 2021/09/14 20:36:42 by tschmitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CCFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRC_PATH = ./src/
OBJ_PATH = ./obj/
OPERATIONS_SRC_PATH = $(SRC_PATH)operations/
OPERATIONS_OBJ_PATH = $(OBJ_PATH)operations/
STACK_SRC_PATH = $(SRC_PATH)stack/
STACK_OBJ_PATH = $(OBJ_PATH)stack/
SORTING_SRC_PATH = $(SRC_PATH)sorting/
SORTING_OBJ_PATH = $(OBJ_PATH)sorting/
INCLUDE_PATH = ./include/
HEADER = $(INCLUDE_PATH)push_swap.h
LIBFT_PATH = ./libs/libft/

NAME = push_swap
LIBFT_NAME = $(LIBFT_PATH)lib/libft.a

SRC = $(SRC_PATH)main.c $(SRC_PATH)parse_input.c \
		$(OPERATIONS_SRC_PATH)push.c $(OPERATIONS_SRC_PATH)reverse.c $(OPERATIONS_SRC_PATH)rotate.c $(OPERATIONS_SRC_PATH)swap.c \
		$(STACK_SRC_PATH)elements.c $(STACK_SRC_PATH)stack_utils.c \
		$(SORTING_SRC_PATH)big_sort.c $(SORTING_SRC_PATH)small_sort.c $(SORTING_SRC_PATH)very_small_sort.c \
		$(SORTING_SRC_PATH)indexing/indexing.c $(SORTING_SRC_PATH)indexing/quick_sort.c
OBJ = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRC))

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

$(NAME): $(OBJ) $(LIBFT_NAME)
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CCFLAGS) $(INCLUDE_FLAGS) $(OBJ) $(LIBFT_NAME) -o $(NAME)
	@echo $(G)Finished [$(NAME)]$(X)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo $(Y)Compiling [$@]...$(X)
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OPERATIONS_OBJ_PATH)
	@mkdir -p $(STACK_OBJ_PATH)
	@mkdir -p $(SORTING_OBJ_PATH)
	@mkdir -p $(SORTING_OBJ_PATH)indexing/
	@$(CC) $(CCFLAGS) $(INCLUDE_FLAGS) -o $@ -c $<
	@printf $(UP)$(CUT)
	@echo $(G)Finished [$@]$(X)
	@printf $(UP)$(CUT)

clean:
	@make -C $(LIBFT_PATH) clean
	@$(RM) -r $(OBJ_PATH)
	@echo $(R)Cleaning"  "[$(OBJ) $(OPERATIONS_OBJ) $(STACK_OBJ)]...$(X)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@echo $(R)Cleaning"  "[$(NAME)]...$(X)

re: fclean all

norm:
	@echo $(G)Checking Norminette...$(X)
	norminette
	@echo $(G)Done$(X)

test: all norm
	@echo $(G)Testing push_swap...$(X)
	@echo $(G)Push Swap should now display error...$(X)
	@echo "./$(NAME) hello world"
	@./$(NAME) hello world || true
	@echo $(G)Push Swap should now display error...$(X)
	@echo "./$(NAME) 1 2 3 4 5 1"
	@./$(NAME) 1 2 3 4 5 1 || true
	@echo $(G)Push Swap should now display error...$(X)
	@echo "./$(NAME) 2147483647 -2147483648"
	@./$(NAME) 2147483648 -2147483649 || true
	@echo $(G)Push Swap should display nothing...$(X)
	./$(NAME) 42
	@echo $(G)Push Swap should display nothing...$(X)
	./$(NAME) 0 1 2 3
	@echo $(G)Push Swap should display nothing...$(X)
	./$(NAME) 0 1 2 3 4 5 6 7 8 9
	@echo $(G)Push Swap should now display nothing...$(X)
	./$(NAME) 1 2 3 4 5
	@echo $(G)WordCount should now display 3...$(X)
	./$(NAME) 1 3 2 4 5 | wc -l
	@echo $(G)Checker should now display OK...$(X)
	./$(NAME) 1 3 2 4 5 | ./checker 1 3 2 4 5
	@echo $(G)Push Swap should now display 3 instructions "(pb sa pa)"...$(X)
	./$(NAME) 1 3 2 4 5
	

.PHONY: all, clean, fcelan, re