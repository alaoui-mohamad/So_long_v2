/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-alaoui <m-alaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:39:00 by m-alaoui          #+#    #+#             */
/*   Updated: 2023/02/25 21:47:03 by m-alaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_st *b, int x, int y)
{
	b->i = 0;
	b->j = 0;
	while (b->arr[b->i])
	{
		while (b->arr[b->i][b->j])
		{
			if (b->arr[b->i][b->j] == 'P')
			{
				complet_move_player(b, x, y);
				return ;
			}
			b->j++;
		}
		b->j = 0;
		b->i++;
	}
}

int	read_key(int keycode, t_st *b)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 0)
		move_player(b, -1, 0);
	if (keycode == 13)
		move_player(b, 0, -1);
	if (keycode == 2)
		move_player(b, 1, 0);
	if (keycode == 1)
		move_player(b, 0, 1);
	mlx_clear_window(b->mlx, b->win);
	draw_files(b);
	return (0);
}

void	read_files(t_st *b)
{
	b->exit = mlx_xpm_file_to_image(b->mlx, "assets/exit.xpm", \
									&b->width, &b->height);
	b->empty = mlx_xpm_file_to_image(b->mlx, "assets/empty.xpm", &b->width, \
									&b->height);
	b->col = mlx_xpm_file_to_image(b->mlx, "assets/col.xpm", &b->width, \
									&b->height);
	b->wall = mlx_xpm_file_to_image(b->mlx, "assets/wall.xpm", &b->width, \
									&b->height);
	b->player = mlx_xpm_file_to_image(b->mlx, "assets/player.xpm", &b->width, \
									&b->height);
}

void	drow_player_exit(t_st *b)
{
	if (b->arr[b->i][b->j] == 'E')
	{
		mlx_put_image_to_window(b->mlx, b->win, b->empty, SQUARE * b->j, \
								SQUARE * b->i);
		mlx_put_image_to_window(b->mlx, b->win, b->exit, SQUARE * b->j, \
								SQUARE * b->i);
	}
	if (b->arr[b->i][b->j] == 'P')
	{
		mlx_put_image_to_window(b->mlx, b->win, b->empty, SQUARE * b->j, \
								SQUARE * b->i);
		mlx_put_image_to_window(b->mlx, b->win, b->player, SQUARE * b->j, \
								SQUARE * b->i);
	}
}

void	draw_files(t_st *b)
{
	b->i = 0;
	while (b->i < b->y)
	{
		b->j = 0;
		while (b->j < b->x)
		{
			if (b->arr[b->i][b->j] == '1')
				mlx_put_image_to_window(b->mlx, b->win, b->wall, SQUARE * b->j, \
										SQUARE * b->i);
			if (b->arr[b->i][b->j] == '0')
				mlx_put_image_to_window(b->mlx, b->win, b->empty, \
										SQUARE * b->j, SQUARE * b->i);
			if (b->arr[b->i][b->j] == 'C')
			{
				mlx_put_image_to_window(b->mlx, b->win, b->empty,
					SQUARE * b->j, SQUARE * b->i);
				mlx_put_image_to_window(b->mlx, b->win, b->col,
					SQUARE * b->j + SQUARE / 4, SQUARE * b->i + SQUARE / 4);
			}
			drow_player_exit(b);
			b->j++;
		}
		b->i++;
	}
}
