
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>

#define WIDTH 256
#define HEIGHT 256

typedef struct l_st
{
	void *mlx;
	void *win;

	void *img;
	int coins;
	int start;
	int end;
	int x;
	int y;
	int width;
	int height;

	char **arr;
	char *line;
	int j;
	int i;
} t_st;

#include <string.h>
#include "get_next_line/get_next_line_bonus.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] && (s1[i] == s2[i]) && n--)
		i++;
	if (n == 0)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
char *ft_strrchr(const char *s, int c)
{
	char *str;

	int len;

	str = (char *)s;
	len = ft_strlen(s);
	if ((char)c == '\0')
		return (str + len);
	while (len >= 0)
	{
		if (str[len] == (char)c)
			return (str + len);
		len--;
	}
	return (0);
}
void ft_putstr_fd(char *s, int fd)
{
	int i;
	if (!s)
		return ((void)0);
	i = ft_strlen(s);
	write(fd, s, i);
}
int read_file(char *path)
{
	char *extension;
	int fd;
	extension = ft_strrchr(path, '.');
	if (extension == 0 || ft_strncmp(".ber", extension, ft_strlen(extension)))
	{
		ft_putstr_fd("Error", 2);
	}
	fd = open(path, O_RDONLY | O_NOFOLLOW);

	return (fd);
}
int ft_hieght(char **av)
{
	int height;
	int fd;

	height = 0;
	fd = read_file(av[1]);

	while (get_next_line(fd))
	{
		height++;
	}
	return (height);
}
int check_allowed_char(char *line)
{
	int i;
	int n;

	i = 0;
	n = strlen(line);
	while (i < n)
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'C' && line[i] != 'E' && line[i] != 'P')
		{
			printf("map not valid (not allowed char)");
			exit(0);
		}
		i++;
	}
	return (1);
}
void delete_backslash(char *line)
{
	int i;
	int n;

	i = 0;
	n = strlen(line);
	while (i < n)
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
}
int check_map_valid(char **line)
{
	t_st b;

	b.i = 0;
	b.j = 0;
	b.start = 0;
	b.end = 0;
	while (line[b.i])
	{
		while (line[b.i][b.j])
		{
			if (line[b.i][b.j] == 'P')
				b.start++;
			if (line[b.i][b.j] == 'E')
				b.end++;
			b.j++;
		}
		b.j = 0;
		b.i++;
	}
	if (b.start != 1 || b.end != 1)
	{
		printf("map not valid (more then one start or end))");
		exit(0);
	}
	return (1);
}
char **read_map(int ac, char **av)
{
	t_st b;

	static char **map;
	int fd;

	b.i = 0;
	b.height = ft_hieght(av);
	fd = read_file(av[1]);
	map = (char **)malloc(sizeof(char *) * (b.height + 1));
	map[b.height] = NULL;
	while (b.i < b.height)
	{
		map[b.i] = get_next_line(fd);
		delete_backslash(map[b.i]);
		check_allowed_char(map[b.i]);
		if ((ft_strlen(map[b.i]) == 0))
		{
			printf("map not valid (backslash)");
			exit(0);
		}
		printf(" line %d -> %s \n", b.i, map[b.i]);
		b.i++;
	}
	return (map);
}
int check_map_equal(char **line)
{
	int i;
	int j;
	int n;

	i = 0;
	j = 0;
	n = ft_strlen(line[0]);
	while (line[i])
	{
		if (ft_strlen(line[i]) != n)
		{
			printf("map not valid (not equal)");
			exit(0);
		}
		i++;
	}
	return (1);
}
void check_heads(char *line)
{
	int j;

	j = 0;

	while (line[j])
	{
		printf("%c", line[j]);
		if (line[j] != '1')
		{
			printf("map not valid (not wall)");
			exit(0);
		}
		j++;
	}
}
int ft_count_colums(char **line)
{
	int j;

	j = -1;
	while (line[++j])
	{
		if (line[j][0] == '\0')
		{
			break;
		}
	}
	return (j);
}
int  check_wall_map(char **line)
{
	t_st b;

	b.i = 0;
	b.j = 0;
	b.width = ft_strlen(line[0]); 
	b.height = ft_count_colums(line);
	while (line[b.i])
	{
		if (b.i == 0 || b.i == b.height - 1)
		{
			check_heads(line[b.i]);
		}
		if (line[b.i][b.j] != '1' || line[b.i][b.width - 1] != '1')
		{

			printf("map not valid (not wall)");
			exit(0);
		}
		b.j = 0;
		b.i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	t_st b;
	int len;
	b.arr = read_map(ac, av);
	len = ft_strlen(b.arr[0]);


	if (check_map_valid(b.arr) && check_map_equal(b.arr) && check_wall_map(b.arr))
		printf("OK");
	else
		printf("Error map not valid");
}
