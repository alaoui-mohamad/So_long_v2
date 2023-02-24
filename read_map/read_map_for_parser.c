/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_for_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-alaoui <m-alaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:24:52 by m-alaoui          #+#    #+#             */
/*   Updated: 2023/02/24 20:25:29 by m-alaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_hieght(char **av)
{
	int	height;
	int	fd;

	height = 0;
	fd = read_file(av[1]);

	while (get_next_line(fd))
	{
		height++;
	}
	return (height);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		len;

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

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ((void)0);
	i = ft_strlen(s);
	write(fd, s, i);
}

int	read_file(char *path)
{
	char	*extension;
	int		fd;

	extension = ft_strrchr(path, '.');
	if (extension == 0 || ft_strncmp(".ber", extension, ft_strlen(extension)))
	{
		ft_putstr_fd("Error", 2);
	}
	fd = open(path, O_RDONLY | O_NOFOLLOW);

	return (fd);
}

char	**read_map(char **av)
{
	t_st		b;
	static char	**map;
	int			fd;

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
			free_map(map);
			print_simple_error("Error");
		}
		b.i++;
	}
	return (map);
}