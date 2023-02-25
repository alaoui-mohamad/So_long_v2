/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_for_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-alaoui <m-alaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:24:52 by m-alaoui          #+#    #+#             */
/*   Updated: 2023/02/25 03:54:52 by m-alaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_hieght(char **av)
{
	int height;
	int fd;
	char *line;

	height = 0;
	fd = read_file(av[1]);
	line = get_next_line(fd);
	while (line)
	{
		height++;
		line = get_next_line(fd);
	}
	return (height);
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
void check_line_backslach(char *line)
{
	int n;
	n = ft_strlen(line);
	if (line[n - 1] == '\n')
		print_simple_error("Error : Map is not closed \n");
}

char **read_map(char **av)
{
	t_st b;
	static char **map;
	int fd;

	b.i = 0;
	b.height = ft_hieght(av);
	fd = read_file(av[1]);
	map = (char **)malloc(sizeof(char *) * (b.height + 1));
	if (!map)
		free_map(map);
	map[b.height] = NULL;
	while (b.i < b.height)
	{
		map[b.i] = get_next_line(fd);
		check_allowed_char(map[b.i]);
		b.i++;
	}
	return (map);
}
