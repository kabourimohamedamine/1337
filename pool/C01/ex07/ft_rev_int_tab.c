/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 17:05:31 by mkabouri          #+#    #+#             */
/*   Updated: 2026/08/15 15:26:35 by mkabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b )
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	f;

	f = 0 ;
	size = size - 1 ;
	while (f <= size)
	{
		swap(&tab[f], &tab[size]);
		size--;
		f++;
	}
}
/* int main(){
	int a[] = {1,2,3,4,5,6};
	ft_rev_int_tab(a,5);
	return 0;
}*/
