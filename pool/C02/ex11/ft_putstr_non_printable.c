/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 14:14:05 by mkabouri          #+#    #+#             */
/*   Updated: 2026/08/19 13:28:11 by mkabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	unprint(char str)
{
	if (str < 32 || str == 127)
		return (1);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char	*hex;

	hex = "0123456789abcdef";
	while (*str != '\0')
	{
		if (unprint(*str))
		{
			ft_putchar('\\');
			ft_putchar(hex[*str / 16]);
			ft_putchar(hex[*str % 16]);
		}
		else
		{
			ft_putchar(*str);
		}
		str++;
	}
}
