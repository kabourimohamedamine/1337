/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabouri <mkabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 14:34:10 by mkabouri          #+#    #+#             */
/*   Updated: 2026/08/29 11:44:26 by mkabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	*range = malloc((max - min) * sizeof(int));
	if (*range == NULL)
		return (-1);
	while (min + i < max)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (max - min);
}
