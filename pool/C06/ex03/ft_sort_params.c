/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 22:21:37 by mkabouri          #+#    #+#             */
/*   Updated: 2026/08/25 08:31:03 by mkabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	swap(char **s1, char **s2)
{
	char	*temp ;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	if (argc > 1)
	{
		while (j < argc - 1)
		{
			i = 0;
			while (i < argc - j - 1)
			{
				if (ft_strcmp(argv[i], argv[i + 1]) > 0)
					swap(&argv[i], &argv[i + 1]);
				i++;
			}
			j++;
		}
		i = 1;
		while (i < argc)
		{
			putstr(argv[i]);
			i++;
		}
	}	
}
