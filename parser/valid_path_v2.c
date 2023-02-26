/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-alaoui <m-alaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:25:00 by m-alaoui          #+#    #+#             */
/*   Updated: 2023/02/26 20:25:11 by m-alaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char *check_c_isblocked(char *line, int position, int n)
{
	if (line[position - n - 1] == 'P')
	{
		line[position] = 'P';
		return (line);
	}
	if (line[position - 1] == 'P')
	{
		line[position] = 'P';
		return (line);
	}
	if (line[position + 1] == 'P')
	{
		line[position] = 'P';
		return (line);
	}
	if (line[position + n - 1] == 'P')
	{
		line[position] = 'P';
		return (line);
	}
	return (line);
}

char *loop_map_check_c(char *line , int n)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
		{
			line = check_c_isblocked(line, i, n);
		}
		i++;
	}
	return (line);
}