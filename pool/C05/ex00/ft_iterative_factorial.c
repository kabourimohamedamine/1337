/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 09:48:22 by mkabouri          #+#    #+#             */
/*   Updated: 2026/08/25 10:22:53 by mkabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_iterative_factorial(int nb)
{
	int	j;

	j = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		j = j * nb;
		nb--;
	}
	return (j);
}
int main()
{
	printf("%llu",ft_iterative_factorial(100));
}
