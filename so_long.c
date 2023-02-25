
#include "so_long.h"

int draw_map(char **map, int coins)
{
	t_st b;

	b.count_m = 0;
	b.arr = map;
	b.coins = coins;
	b.mlx = mlx_init();
	b.y = ft_count_colums(map);
	b.x = ft_strlen(map[0]);
	b.win = mlx_new_window(b.mlx, b.x * SQUARE, b.y * SQUARE, "So Long");
	read_files(&b);
	draw_files(&b);
	mlx_hook(b.win, 2, 0, read_key, &b);
	mlx_hook(b.win, 17, 0, destory, &b);

	mlx_loop(b.mlx);

	return (0);
}

char	*double_pointer_to_char(char **line)
{
	int i;
	int j;
	int n;
	char *str;

	i = 0;
	j = 0;
	n = ft_strlen(line[0]);
	str = (char *)malloc(sizeof(char) * (n * ft_count_colums(line) + 1));
	if (!str)
		free(str);
	while (line[i])
	{
		while (line[i][j -1])
		{
			str[i * n + j] = line[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	str[i * n + j] = '\0';
	return (str);
}

void check_map(t_st *b)
{
	b->width = ft_strlen(b->arr[0]);
	b->height = ft_count_colums(b->arr);
	check_line_backslach(b->arr[b->height - 1]);
	delete_backslash(b->arr);
	check_allowed_char(b->arr);
	check_map_valid(b->arr);
	check_map_equal(b->arr);
	check_wall_map(b->arr);
	check_map_rectangular(b->arr);
	check_e_isblocked(b->line, b->width);
}

char **parser_map(int ac, char **av)
{
	t_st b;
	int len;
	int i = 0;
	if (ac != 2)
		print_simple_error("Error : Wrong number of arguments \n");
	b.arr = read_map(av);
	b.line = double_pointer_to_char(b.arr);
	check_map(&b);
	// b.arr = delete_backslash(b.arr);
	b.line = check_path_valid(b.line, player_position(b.arr), len);
	check_path(b.line);
	return (b.arr);
}

int	main(int argc, char **argv)
{
	char	**map;
	int		count_c;

	map = parser_map(argc, argv);
	count_c = count_collec(map);
	draw_map(map, count_c);

	return (0);
}
