/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 17:18:47 by mkabouri          #+#    #+#             */
/*   Updated: 2026/08/15 14:19:29 by mkabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_check(int *a, int *b)
{
	int	temp;

	if (*a > *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < (size - 1))
	{
		j = 0;
		while (j < (size - 1 - i))
		{
			ft_check(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}
