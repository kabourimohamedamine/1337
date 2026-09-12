/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabouri <mkabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 15:42:53 by mkabouri          #+#    #+#             */
/*   Updated: 2026/09/01 12:21:07 by mkabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	put_char(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		put_char('-');
		nb = -1 * nb ;
	}
	if (nb <= 9)
	{
		put_char((nb % 10) + '0');
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		put_char((nb % 10) + '0');
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		put_char('\n');
		ft_putnbr(par[i].size);
		put_char('\n');
		ft_putstr(par[i].copy);
		put_char('\n');
		i++;
	}
}
