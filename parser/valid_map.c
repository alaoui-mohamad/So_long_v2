/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-alaoui <m-alaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 04:09:17 by m-alaoui          #+#    #+#             */
/*   Updated: 2023/02/25 17:44:57 by m-alaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void check_heads(char *line)
{
	int j;

	j = 0;

	while (line[j])
	{
		if (line[j] != '1')
		{
			free(line);
			print_simple_error("Error : map not valid (head) \n");
		}
		j++;
	}
}

int check_allowed_char(char **line)
{
	int i;
	int n;
	int j;

	i = 0;
	n = ft_strlen(line[0]);
	while (line[i])
	{
		j = 0;
		while (j < n - 1)
		{
			if (line[i][j] != '1' && line[i][j] != '0' && line[i][j] != 'C' &&
				line[i][j] != 'E' && line[i][j] != 'P' && line[i][j] != '\n')
			{
				free(line);
				print_simple_error("Error : map not valid ! (not allowed char) \n");
			}
			j++;
		}
		i++;
	}
	return (1);
}

char **delete_backslash(char **line)
{
	int i;
	int n;

	i = 0;
	n = ft_strlen(line[0]);
	while (line[i])
	{
		if (line[i][n - 1] == '\n')
			line[i][n - 1] = '\0';
		i++;
	}
	return (line);
}

int check_map_equal(char **line)
{
	int i;
	int j;
	int n;

	i = 0;
	j = 0;
	n = ft_strlen(line[0]);
	while (line[i])
	{
		if (ft_strlen(line[i]) != n)
		{
			free_map(line);
			print_simple_error("Error : map not valid\n");
		}
		i++;
	}
	return (1);
}

int check_map_valid(char **line)
{
	t_st b;

	b.i = 0;
	b.j = 0;
	b.start = 0;
	b.end = 0;
	while (line[b.i])
	{
		while (line[b.i][b.j])
		{
			if (line[b.i][b.j] == 'P')
				b.start++;
			if (line[b.i][b.j] == 'E')
				b.end++;
			b.j++;
		}
		b.j = 0;
		b.i++;
	}
	if (b.start != 1 || b.end != 1)
	{
		free_map(line);
		print_simple_error("Error : map not valid (start or end) \n");
	}
	return (1);
}