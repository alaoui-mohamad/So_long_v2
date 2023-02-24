
#include "so_long.h"


int draw_map(char **map, int coins)
{
    t_st b;

    b.arr = map;
    b.coins = coins;
    b.mlx = mlx_init();
    b.y = ft_count_colums(map);
    b.x = ft_strlen(map[0]);
    b.win = mlx_new_window(b.mlx, b.x * SQUARE_SIZE, b.y * SQUARE_SIZE, "My Map");
    read_files(&b);
    draw_files(&b);
    mlx_hook(b.win, 2, 0, read_key, &b);
    mlx_loop(b.mlx);

    return 0;
}

char *double_pointer_to_char(char **line)
{
	int i;
	int j;
	int n;
	char *str;

	i = 0;
	j = 0;
	n = ft_strlen(line[0]);
	str = (char *)malloc(sizeof(char) * (n * ft_count_colums(line) + 1));
	while (line[i])
	{
		while (line[i][j])
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

void check_map(char **line)
{
	check_map_valid(line);
	check_map_equal(line);
	check_wall_map(line);
	check_map_rectangular(line);
}
char **parser_map(int ac, char **av)
{
	t_st b;
	int len;
	if (ac != 2)
	{
		printf("Error: wrong number of arguments \n");
		exit(0);
	}
	b.arr = read_map(av);
	check_map(b.arr);
	b.line = double_pointer_to_char(b.arr);
	len = ft_strlen(b.arr[0]);
	b.line = check_path_valid(b.line, player_position(b.arr), len);
	printf("%s\n", b.line);
	check_path(b.line);
	return (b.arr);
}

int main(int argc, char const *argv[])
{
	char **map;
	int count_c;
	map = parser_map(argc, (char **)argv);
	count_c = count_collectibles(map);
	draw_map(map, count_c);
	return 0;
}

