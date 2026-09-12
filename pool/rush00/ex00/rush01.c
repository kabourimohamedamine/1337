/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 14:34:57 by mkabouri          #+#    #+#             */
/*   Updated: 2026/08/16 16:02:48 by mkabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_borders(int x, int y, int row)
{
	int	j;

	j = 0;
	while (j < x)
	{
		if (j == 0 && row == 0)
			ft_putchar('/');
		else if (j == 0 && row == y - 1)
			ft_putchar('\\');
		else if (j == x - 1 && row == 0)
			ft_putchar('\\');
		else if (j == x - 1 && row == y - 1)
			ft_putchar('/');
		else
			ft_putchar('*');
		j++;
	}
}

void	print_rows(int x)
{
	int	j;

	j = 0;
	while (j < x)
	{
		if (j == 0 || j == x - 1)
			ft_putchar('*');
		else
			ft_putchar(' ');
		j++;
	}
}

void	rush(int x, int y)
{
	int	i;

	if (x <= 0 || y <= 0)
		return ;
	i = 0;
	while (i < y)
	{
		if (i == 0 || i == y - 1)
			print_borders(x, y, i);
		else
			print_rows(x);
		ft_putchar('\n');
		i++;
	}
}
