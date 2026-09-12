/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:18:00 by marvin            #+#    #+#             */
/*   Updated: 2026/08/29 14:02:29 by mkabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	strl(char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

int	str_len(int size, char **s, char *sep)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	k = 0;
	l = 0;
	while (i < size)
	{
		j = 0;
		while (s[i][j])
			j++;
		k += j;
		i++;
	}
	while (sep[l])
		l++;
	if (size > 0)
		k += l * (size - 1);
	return (k + 1);
}

void	ft_copy(int size, char **strs, char *sep, char *p)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			p[k++] = strs[i][j++];
		}
		l = 0;
		while (sep[l] && i < size - 1)
		{
			p[k++] = sep[l++];
		}
		i++;
	}
	p[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*p;

	p = (char *)malloc(sizeof(char) * str_len(size, strs, sep));
	if (p == NULL)
		return (NULL);
	ft_copy(size, strs, sep, p);
	return (p);
}
int main()
{
	char *a[] = {"hello","le","batan"};
	char *p = ft_strjoin(5,a,", ?");
	printf("%s",p);
	free(p);
}
