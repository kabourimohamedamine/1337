/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 18:14:17 by mkabouri          #+#    #+#             */
/*   Updated: 2026/08/23 16:20:15 by mkabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	fchar(char c)
{
	write(1, &c, 1);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	basev(char *base, int len)
{
	int	j;
	int	i;

	i = 0;
	if (len < 2)
		return (0);
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	long	nb;

	len = str_len(base);
	nb = nbr;
	if (basev(base, len))
	{
		if (nb < 0)
		{
			fchar('-');
			nb = -1 * nb ;
		}
		if (nb < len)
			fchar(base[nb % len]);
		else
		{
			ft_putnbr_base((nb / len), base);
			fchar(base[nb % len]);
		}
	}
}
