/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabouri <mkabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 13:11:16 by mkabouri          #+#    #+#             */
/*   Updated: 2026/08/29 13:25:57 by mkabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*p;

	i = 0;
	if (min >= max)
		return (NULL);
	p = malloc((max - min) * sizeof(int));
	while (min < max)
	{
		p[i] = min;
		i++;
		min++;
	}
	return (p);
}
