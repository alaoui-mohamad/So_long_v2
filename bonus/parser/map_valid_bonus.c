/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-alaoui <m-alaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 04:08:53 by m-alaoui          #+#    #+#             */
/*   Updated: 2023/02/27 03:48:58 by m-alaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && (s1[i] == s2[i]) && n--)
		i++;
	if (n == 0)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_count_colums(char **line)
{
	int	j;

	j = -1;
	while (line[++j])
	{
		if (line[j][0] == '\0')
		{
			break ;
		}
	}
	return (j);
}

int	check_map_rectangular(char **line)
{
	int	n;
	int	m;

	n = ft_strlen(line[0]);
	m = ft_count_colums(line);
	if (m == n)
	{
		free_map(line);
		print_simple_error("Error : map not valid (not rectangular) \n");
	}
	return (1);
}

int	check_wall_map(char **line)
{
	t_st	b;

	b.i = 0;
	b.j = 0;
	b.width = ft_strlen(line[0]);
	b.height = ft_count_colums(line);
	while (line[b.i])
	{
		if (b.i == 0 && b.i == b.height - 1)
		{
			check_heads(line[b.i]);
		}
		if (line[b.i][b.j] != '1' || line[b.i][b.width - 1] != '1')
		{
			free_map(line);
			print_simple_error("Error map not valid (not wall) \n");
		}
		b.j = 0;
		b.i++;
	}
	return (1);
}
