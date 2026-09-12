/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:28:47 by mkabouri          #+#    #+#             */
/*   Updated: 2026/09/01 12:47:24 by mkabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	len(char *a)
{
	int	i;

	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*a;

	i = 0;
	a = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!a)
		return (NULL);
	while (i < ac)
	{
		a[i].size = len(av[i]);
		a[i].str = av[i];
		a[i].copy = ft_strdup(av[i]);
		if (!a[i].copy)
		{
			while (--i >= 0)
				free(a[i].copy);
			free(a);
			return (NULL);
		}
		i++;
	}
	a[i].str = 0;
	return (a);
}
