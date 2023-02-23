CC=CC
FLAGS= -I include/push_swap.h
AR=ar cr
RM=rm -rf
FILES=  src/instructions/pp_function src/instructions/rr_function src/instructions/rrr_function \
		src/instructions/ss_function src/parsing_function/ft_split src/parsing_function/need_function \
		src/parsing_function/libft_import src/parsing_function/libft_import2 \
		src/sorting/need_function src/sorting/push_function src/sorting/hard_sort push_swap
		
BFILES  = src/instructions/pp_function src/instructions/rr_function src/instructions/rrr_function \
		src/instructions/ss_function src/parsing_function/ft_split src/parsing_function/need_function \
		src/parsing_function/libft_import src/parsing_function/libft_import2 \
		src/sorting/need_function src/sorting/push_function src/sorting/hard_sort \
		src/get_next_line/get_next_line_bonus src/get_next_line/get_next_line_utils_bonus \
		checker

OBJ=$(FILES:=.o)
BOBJ=$(BFILES:=.o)
NAME=push_swap

.PHONY: all bonus clean fclean re

all: $(NAME)

bonus: $(BOBJ)
	$(CC) $(BOBJ) -o checker

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o push_swap

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all