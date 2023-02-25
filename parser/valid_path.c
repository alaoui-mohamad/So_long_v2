/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-alaoui <m-alaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:23:34 by m-alaoui          #+#    #+#             */
/*   Updated: 2023/02/25 22:20:11 by m-alaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

char	*check_path_valid(char *line, int p, int n)
{
	if ((line[p - n] == '0' || line[p - n] == 'C') && (line[p] != '1'))
	{
		line[p] = 'P';
		check_path_valid(line, p - n, n);
	}
	if ((line[p - 1] == '0' || line[p - 1] == 'C') && (line[p] != '1'))
	{
		line[p] = 'P';
		check_path_valid(line, p - 1, n);
	}
	if ((line[p + 1] == '0' || line[p + 1] == 'C') && (line[p] != '1'))
	{
		line[p] = 'P';
		check_path_valid(line, p + 1, n);
	}
	if ((line[p + n] == '0' || line[p + n] == 'C') && (line[p] != '1'))
	{
		line[p] = 'P';
		check_path_valid(line, p + n, n);
	}
	return (line);
}

int	check_path(char *line)
{
	int	i;

	i = 0;
	printf("line = %s", line);
	while (line[i])
	{
		if (line[i] == 'C')
		{
			free(line);
			print_simple_error("Error : can't collect all the coins");
		}
		i++;
	}
	return (1);
}
