/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabouri <mkabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 18:11:47 by mkabouri          #+#    #+#             */
/*   Updated: 2026/09/02 18:13:41 by mkabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static char	*read_line(int fd)
{
	char	*line;
	char	c;
	int		len;
	int		cap;

	cap = 128;
	line = malloc(sizeof(char) * cap);
	if (!line)
		return (NULL);
	len = 0;
	while (read(fd, &c, 1) > 0 && c != '\n')
	{
		if (len + 1 >= cap)
		{
			cap *= 2;
			line = realloc(line, cap);
			if (!line)
				return (NULL);
		}
		line[len++] = c;
	}
	if (len == 0 && c != '\n')
		return (free(line), NULL);
	line[len] = '\0';
	return (line);
}

static int	validate_row(t_map *map, char *line)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] != map->empty && line[j] != map->obstacle)
			return (0);
		j++;
	}
	if (map->cols == 0)
		map->cols = j;
	else if (map->cols != j)
		return (0);
	return (j > 0);
}

t_map	*read_map(int fd)
{
	t_map	*map;
	char	*header;
	int		i;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->cols = 0;
	map->grid = NULL;
	header = read_line(fd);
	if (!header || !parse_header(map, header))
		return (free(header), free_map(map), NULL);
	free(header);
	map->grid = malloc(sizeof(char *) * map->rows);
	if (!map->grid)
		return (free_map(map), NULL);
	i = 0;
	while (i < map->rows)
	{
		map->grid[i] = read_line(fd);
		if (!map->grid[i] || !validate_row(map, map->grid[i]))
			return (free_map(map), NULL);
		i++;
	}
	return (map);
}
