/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-alaoui <m-alaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:23:34 by m-alaoui          #+#    #+#             */
/*   Updated: 2023/03/13 00:37:34 by m-alaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	count_collec(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

int	player_position(char **line)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = ft_strlen(line[0]);
	while (line[i])
	{
		while (line[i][j])
		{
			if (line[i][j] == 'P')
			{
				return (i * n + j);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

char	*check_path_valid(char *line, int position, int n)
{
	if (line[position] == 'E')
		line[position] = 'K';
	if (line[position] == '0' || line[position] == 'C' || line[position] == 'P')
	{
		line[position] = 'K';
		check_path_valid(line, position - n, n);
		check_path_valid(line, position - 1, n);
		check_path_valid(line, position + 1, n);
		check_path_valid(line, position + n, n);
	}
	return (line);
}

int	check_path(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'C' || line[i] == 'E')
		{
			free(line);
			print_simple_error("Error : can't collect all the coins");
		}
		i++;
	}
	return (1);
}

void	protect_malloc(t_st *b)
{
	if (b->exit == NULL || b->empty == NULL || b->col == NULL
		|| b->wall == NULL || b->player == NULL)
	{
		print_simple_error("Error");
	}
}
