/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabouri <mkabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 18:11:59 by mkabouri          #+#    #+#             */
/*   Updated: 2026/09/02 18:13:51 by mkabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	min3(int a, int b, int c)
{
	int	m;

	m = a;
	if (b < m)
		m = b;
	if (c < m)
		m = c;
	return (m);
}

static void	draw_square(t_map *map, t_sq sq)
{
	int	r;
	int	c;

	r = sq.r - sq.size + 1;
	while (r <= sq.r)
	{
		c = sq.c - sq.size + 1;
		while (c <= sq.c)
		{
			map->grid[r][c] = map->full;
			c++;
		}
		r++;
	}
}

static void	print_grid(t_map *map)
{
	int	r;

	r = 0;
	while (r < map->rows)
	{
		ft_putstr(map->grid[r]);
		ft_putchar('\n');
		r++;
	}
}

static void	process_dp(t_map *map, int **dp, t_sq *best)
{
	int	r;
	int	c;

	r = -1;
	while (++r < map->rows)
	{
		dp[r] = malloc(sizeof(int) * map->cols);
		c = -1;
		while (++c < map->cols)
		{
			if (map->grid[r][c] == map->obstacle)
				dp[r][c] = 0;
			else if (r == 0 || c == 0)
				dp[r][c] = 1;
			else
				dp[r][c] = min3(dp[r - 1][c], dp[r][c - 1],
						dp[r - 1][c - 1]) + 1;
			if (dp[r][c] > best->size)
			{
				best->size = dp[r][c];
				best->r = r;
				best->c = c;
			}
		}
	}
}

void	solve(t_map *map)
{
	int		**dp;
	int		r;
	t_sq	best;

	best.size = 0;
	best.r = 0;
	best.c = 0;
	dp = malloc(sizeof(int *) * map->rows);
	if (!dp)
		return ;
	process_dp(map, dp, &best);
	draw_square(map, best);
	print_grid(map);
	r = 0;
	while (r < map->rows)
	{
		free(dp[r]);
		r++;
	}
	free(dp);
}
