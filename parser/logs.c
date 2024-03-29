/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-alaoui <m-alaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:31:39 by m-alaoui          #+#    #+#             */
/*   Updated: 2023/03/12 22:51:15 by m-alaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	protect_malloc(t_st *b)
{
	if (b->exit == NULL || b->empty == NULL || b->col == NULL
		|| b->wall == NULL || b->player == NULL)
	{
		print_simple_error("Error");
	}
}
