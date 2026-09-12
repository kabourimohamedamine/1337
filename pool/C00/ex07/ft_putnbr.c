/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 12:59:22 by mkabouri          #+#    #+#             */
/*   Updated: 2026/08/20 14:54:02 by mkabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
/*	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}*/
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
int main()
{
	int a = -2147483648;
	ft_putnbr(a);
}	
