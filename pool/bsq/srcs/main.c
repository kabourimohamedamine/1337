/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabouri <mkabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 18:11:41 by mkabouri          #+#    #+#             */
/*   Updated: 2026/09/02 18:13:33 by mkabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	process_fd(int fd)
{
	t_map	*map;

	map = read_map(fd);
	if (!map)
	{
		put_map_error();
		return ;
	}
	solve(map);
	free_map(map);
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	if (argc == 1)
		process_fd(0);
	else
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd < 0)
				put_map_error();
			else
			{
				process_fd(fd);
				close(fd);
			}
			if (i < argc - 1)
				ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
