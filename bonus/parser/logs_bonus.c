/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-alaoui <m-alaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:31:39 by m-alaoui          #+#    #+#             */
/*   Updated: 2023/02/26 17:28:12 by m-alaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	print_error(t_st *b, char *str)
{
	free_map(b->arr);
	free(b->line);
	free_window(b);
	ft_putstr_fd(str, 1);
	exit(0);
}

void	print_simple_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(0);
}

void	free_window(t_st *b)
{
	mlx_destroy_window(b->mlx, b->win);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	draw_score(t_st *b)
{
	mlx_string_put(b->mlx, b->win, SQUARE / 6, SQUARE / 6,
		0x7c2222, "Score : ");
	b->count_m_c = ft_itoa(b->count_m);
	mlx_string_put(b->mlx, b->win, SQUARE * 3,
		(SQUARE / 6), 0x7c2222, b->count_m_c);
}