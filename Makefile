CC=CC
FLAGS= -I so_long.h
AR=ar cr
RM=rm -rf
FILES=  get_next_line/get_next_line_bonus \
		get_next_line/get_next_line_utils_bonus \
		parser/valid_map \
		parser/map_valid \
		parser/valid_path \
		read_map/read_map_for_parser \
		so_long \

		


OBJ=$(FILES:=.o)
# BOBJ=$(BFILES:=.o)
NAME=so_long

.PHONY: all bonus clean fclean re

all: $(NAME)

# bonus: $(BOBJ)
# 	$(CC) $(BOBJ) -o checker

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o so_long

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all