NAME = push_swap
CHECKER = checker

M_SRC = push_mandatory/big_sort.c		  	\
		push_mandatory/big_sort_part2.c 	\
		push_mandatory/check_args.c			\
		push_mandatory/choose_sort.c		\
		push_mandatory/create_stacks.c		\
		push_mandatory/instructions.c		\
		push_mandatory/instructions_2.c		\
		push_mandatory/main.c				\
		push_mandatory/special_cases.c		\
		push_mandatory/tools.c

B_SRC =	push_swap_bonus/check_args_bonus.c		\
		push_swap_bonus/checker_bonus.c 		\
		push_swap_bonus/create_stacks_bonus.c	\
		push_swap_bonus/instructions_bonus.c	\
		push_swap_bonus/instructions_2_bonus.c	\
		push_swap_bonus/get_next_line/get_next_line.c \
		push_swap_bonus/get_next_line/get_next_line_utils.c

M_OBJ = big_sort.o		  	\
		big_sort_part2.o 	\
		check_args.o		\
		choose_sort.o		\
		create_stacks.o		\
		instructions.o		\
		instructions_2.o	\
		main.o				\
		special_cases.o		\
		tools.o

B_OBJ = check_args_bonus.o		\
		checker_bonus.o 		\
		create_stacks_bonus.o	\
		instructions_bonus.o	\
		instructions_2_bonus.o	\
		get_next_line.o			\
		get_next_line_utils.o

FLAGS = -Wall -Wextra -Werror -c

all : $(NAME)

$(NAME): $(M_SRC)
		@gcc $(FLAGS) $(M_SRC)
		@gcc $(M_OBJ) -o $(NAME)
		@echo "Make mandatory part"

bonus : $(CHECKER)

$(CHECKER):	
			@gcc $(FLAGS) $(B_SRC)
			@gcc $(B_OBJ) -o $(CHECKER)
			@echo "Make bonus part"

clean :
	rm -f $(M_OBJ) $(B_OBJ)

fclean :
	rm -f $(M_OBJ) $(NAME) $(B_OBJ) $(CHECKER)

re : fclean all

.PHONY : bonus all re fclean clean
