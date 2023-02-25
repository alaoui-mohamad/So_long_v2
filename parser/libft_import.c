/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_import.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-alaoui <m-alaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:30:47 by m-alaoui          #+#    #+#             */
/*   Updated: 2023/02/25 04:10:28 by m-alaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	print_error(b, "Error : window closed \n");
	exit(0);
	return (0);
}

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