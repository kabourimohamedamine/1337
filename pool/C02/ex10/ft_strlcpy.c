/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 10:09:06 by mkabouri          #+#    #+#             */
/*   Updated: 2026/08/19 11:35:42 by mkabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	i = 0;
	if (size > 0)
	{
		while (i < size -1 && src[i] != '\0')
		{
			dest[i] = src [i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}
