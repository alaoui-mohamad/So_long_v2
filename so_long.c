
#include "so_long.h"




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
	b.arr = read_map(ac, av);
	check_map(b.arr);
	b.line = double_pointer_to_char(b.arr);
	len = ft_strlen(b.arr[0]);
	b.line = check_path_valid(b.line, player_position(b.arr), len);
	printf("%s\n", b.line);
	check_path(b.line);
	return (b.arr);
}
