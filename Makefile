# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/29 21:22:56 by tschmitt          #+#    #+#              #
#    Updated: 2021/09/15 18:57:48 by tschmitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CCFLAGS = -Wall -Werror -Wextra
INCLUDE_FLAGS = -I $(LIBFT_PATH)include/ -I $(INCLUDE_PATH)
RM = rm -f

NAME = ./push_swap
CHECKER_NAME = ./checker
LIBFT_NAME = $(LIBFT_PATH)lib/libft.a
STACK_NAME = ./libs/stack.a

INCLUDE_PATH = ./include/
HEADER = $(INCLUDE_PATH)push_swap.h
LIBFT_PATH = ./libs/libft/

# PUSH_SWAP VARIABLES
SRC_PATH = ./src/push_swap/
OBJ_PATH = ./obj/push_swap/
SORTING_SRC_PATH = $(SRC_PATH)sorting/
SORTING_OBJ_PATH = $(OBJ_PATH)sorting/

# CHECKER VARIABLES
SRC_CHECKER_PATH = ./src/checker/
OBJ_CHECKER_PATH = ./obj/checker/

# STACK VARIABLES
SRC_STACK_PATH = ./src/stack/
OBJ_STACK_PATH = ./obj/stack/

# PUSH_SWAP FILES
SRC = $(SRC_PATH)main.c $(SRC_PATH)parse_input.c \
		$(SORTING_SRC_PATH)big_sort.c $(SORTING_SRC_PATH)small_sort.c $(SORTING_SRC_PATH)very_small_sort.c \
		$(SORTING_SRC_PATH)indexing/indexing.c $(SORTING_SRC_PATH)indexing/quick_sort.c
OBJ = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRC))

# CHECKER FILES
SRC_CHECKER = $(SRC_CHECKER_PATH)main.c $(SRC_CHECKER_PATH)parse_input.c
OBJ_CHECKER = $(patsubst $(SRC_CHECKER_PATH)%.c, $(OBJ_CHECKER_PATH)%.o, $(SRC_CHECKER))

# STACK FILES
STACK_SRC = $(SRC_STACK_PATH)elements.c $(SRC_STACK_PATH)stack_utils.c \
		$(SRC_STACK_PATH)operations/push.c $(SRC_STACK_PATH)operations/reverse.c $(SRC_STACK_PATH)operations/rotate.c $(SRC_STACK_PATH)operations/swap.c
STACK_OBJ = $(patsubst $(SRC_STACK_PATH)%.c, $(OBJ_STACK_PATH)%.o, $(STACK_SRC))

# COLORS
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all: $(NAME) $(CHECKER_NAME) $(LIBFT_NAME)
	@echo $(G)Finished...$(X)

$(LIBFT_NAME):
	@echo $(Y)Compiling [$(LIBFT_NAME)]...$(X)
	@make -C $(LIBFT_PATH)
	@printf $(UP)$(CUT)
	@echo $(G)Finished [$(LIBFT_NAME)]$(X)

# PUSH_SWAP
$(NAME): $(OBJ) $(LIBFT_NAME) $(STACK_NAME)
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CCFLAGS) $(INCLUDE_FLAGS) $(OBJ) $(LIBFT_NAME) $(STACK_NAME) -o $(NAME)
	@echo $(G)Finished [$(NAME)]$(X)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo $(Y)Compiling [$@]...$(X)
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(SORTING_OBJ_PATH)
	@mkdir -p $(SORTING_OBJ_PATH)indexing/
	@$(CC) $(CCFLAGS) $(INCLUDE_FLAGS) -o $@ -c $<
	@printf $(UP)$(CUT)
	@echo $(G)Finished [$@]$(X)
	@printf $(UP)$(CUT)

# CHECKER
bonus: $(CHECKER_NAME)
	@echo $(G)Finished bonus...$(X)

$(CHECKER_NAME): $(OBJ_CHECKER) $(LIBFT_NAME) $(STACK_NAME)
	@echo $(Y)Compiling [$(CHECKER_NAME)]...$(X)
	@$(CC) $(CCFLAGS) $(INCLUDE_FLAGS) $(OBJ_CHECKER) $(LIBFT_NAME) $(STACK_NAME) -o $(CHECKER_NAME)
	@echo $(G)Finished [$(CHECKER_NAME)]$(X)

$(OBJ_CHECKER_PATH)%.o: $(SRC_CHECKER_PATH)%.c
	@echo $(Y)Compiling [$@]...$(X)
	@mkdir -p $(OBJ_CHECKER_PATH)
	@$(CC) $(CCFLAGS) $(INCLUDE_FLAGS) -o $@ -c $<
	@printf $(UP)$(CUT)
	@echo $(G)Finished [$@]$(X)
	@printf $(UP)$(CUT)

# STACK.A
$(STACK_NAME): $(STACK_OBJ) $(LIBFT_NAME)
	@echo $(Y)Compiling [$(STACK_NAME)]...$(X)
	@ar -crs $(STACK_NAME) $(STACK_OBJ)
	@echo $(G)Finished [$(STACK_NAME)]$(X)

$(OBJ_STACK_PATH)%.o: $(SRC_STACK_PATH)%.c
	@echo $(Y)Compiling [$@]...$(X)
	@mkdir -p $(OBJ_STACK_PATH)/operations
	@$(CC) $(CCFLAGS) $(INCLUDE_FLAGS) -o $@ -c $<
	@printf $(UP)$(CUT)
	@echo $(G)Finished [$@]$(X)
	@printf $(UP)$(CUT)

clean:
	@make -C $(LIBFT_PATH) clean
	@$(RM) -r $(OBJ_PATH)
	@$(RM) -r $(OBJ_CHECKER_PATH)
	@$(RM) -r $(OBJ_STACK_PATH)
	@echo $(R)Cleaning"  "[$(OBJ) $(OPERATIONS_OBJ) $(STACK_OBJ) $(OBJ_CHECKER)]...$(X)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@$(RM) $(CHECKER_NAME)
	@echo $(R)Cleaning"  "[$(NAME) $(CHECKER_NAME)]...$(X)

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