/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 10:53:52 by mkabouri          #+#    #+#             */
/*   Updated: 2026/08/18 10:08:22 by mkabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	alphanum(char str)
{
	if (str >= 'a' && str <= 'z')
		return (1);
	if (str >= 'A' && str <= 'Z')
		return (1);
	if (str >= '0' && str <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 'Z' && str[i] >= 'A')
			str[i] += 32;
		if (str[i] <= 'z' && str[i] >= 'a')
		{
			if (i == 0 || !alphanum(str[i - 1]))
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
