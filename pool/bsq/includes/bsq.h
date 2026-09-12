/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabouri <mkabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 18:11:33 by mkabouri          #+#    #+#             */
/*   Updated: 2026/09/02 18:14:05 by mkabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 8192

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**grid;
}	t_map;

typedef struct s_sq
{
	int	size;
	int	r;
	int	c;
}	t_sq;

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		ft_printable(char c);

void	put_map_error(void);
void	free_map(t_map *map);
int		parse_header(t_map *map, char *str);
t_map	*read_map(int fd);

void	solve(t_map *map);

#endif
