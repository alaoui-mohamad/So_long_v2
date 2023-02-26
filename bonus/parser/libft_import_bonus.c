/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_import_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-alaoui <m-alaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:30:47 by m-alaoui          #+#    #+#             */
/*   Updated: 2023/02/26 18:05:24 by m-alaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	size_t	n;

	n = nb;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n < 10)
		ft_putchar_fd(n + 48, fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

int	destory(t_st *b)
{
	print_error(b, "window is closed !\n");
	exit(0);
	return (0);
}

int	ft_hieght(char **av)
{
	int		height;
	int		fd;
	char	*line;
	int		len;

	height = 0;
	len = 0;
	fd = read_file(av[1]);
	line = get_next_line(fd);
	if (line == NULL)
		print_simple_error("Error \n");
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	return (height);
}

void	complet_move_player(t_st *b, int x, int y)
{
	if (b->arr[b->i + y][b->j + x] == 'E' && b->coins == 0)
	{
		print_error(b, "You win!\n");
	}
	if (b->arr[b->i + y][b->j + x] == 'G')
	{
		print_error(b, "You Lost! \n");
	}
	if (b->arr[b->i + y][b->j + x] == '1' || b->arr[b->i + y][b->j + x] == 'E')
		return ;
	if (b->arr[b->i + y][b->j + x] == 'C')
		b->coins--;
	b->arr[b->i][b->j] = '0';
	b->arr[b->i + y][b->j + x] = 'P';
	b->count_m++;
	return ;
}
