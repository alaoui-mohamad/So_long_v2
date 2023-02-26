CC=CC
FLAGS= -Wall -Wextra -Werror -Imlx
AR=ar cr
RM=rm -rf
FILES=  get_next_line/get_next_line_bonus \
		get_next_line/get_next_line_utils_bonus \
		parser/valid_map \
		parser/map_valid \
		parser/valid_path \
		parser/libft_import \
		parser/logs \
		read_map/read_map_for_parser \
		draw_map \
		so_long 
BFILES  = get_next_line/get_next_line_bonus \
		get_next_line/get_next_line_utils_bonus \
		bonus/parser/valid_map_bonus \
		bonus/parser/map_valid_bonus \
		bonus/parser/valid_path_bonus \
		bonus/parser/libft_import_bonus \
		bonus/parser/logs_bonus \
		bonus/read_map/read_map_for_parser_bonus \
		bonus/draw_map_bonus \
		bonus/so_long_bonus 
OBJ=$(FILES:=.o)
BOBJ=$(BFILES:=.o)
NAME=so_long

NAME_B=so_long_bonus

.PHONY: all bonus clean fclean re

all: $(NAME)

bonus: $(BOBJ) ./bonus/so_long_bonus.h
	$(CC) $(BOBJ) -lmlx -framework OpenGl -framework Appkit  -o $(NAME_B)

$(NAME): $(OBJ) so_long.h
	$(CC) $(OBJ) -lmlx -framework OpenGl -framework Appkit -o $(NAME)

%.o: %.c 
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all