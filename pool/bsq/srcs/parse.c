/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabouri <mkabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 18:11:54 by mkabouri          #+#    #+#             */
/*   Updated: 2026/09/02 18:13:45 by mkabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->grid)
	{
		i = 0;
		while (i < map->rows && map->grid[i])
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	free(map);
}

int	parse_header(t_map *map, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		return (0);
	map->full = str[len - 1];
	map->obstacle = str[len - 2];
	map->empty = str[len - 3];
	str[len - 3] = '\0';
	map->rows = ft_atoi(str);
	if (map->rows <= 0)
		return (0);
	if (!ft_printable(map->empty) || !ft_printable(map->obstacle)
		|| !ft_printable(map->full))
		return (0);
	if (map->empty == map->obstacle || map->empty == map->full
		|| map->obstacle == map->full)
		return (0);
	return (1);
}
