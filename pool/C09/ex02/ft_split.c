/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    :+:      :+:    :+:   */
/*   By: mkabouri <mkabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                #+# me+#+#    #+#           */
/*   Created: 2026/08/31 13:02:51 by mkabouri          #+#    #+#             */
/*   Updated: 2026/08/31 16:49:14 by mkabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_a_sep(char a, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (a == sep[i])
			return (1);
		i++;
	}
	return (0);
}

int	countword(char *str, char *sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_a_sep(str[i], sep))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_a_sep(str[i], sep))
			i++;
	}
	return (count);
}

int	countlen(char *str, char *sep)
{
	int	i;

	i = 0;
	while (str[i] && !is_a_sep(str[i], sep))
		i++;
	return (i);
}

char	**copy(char *str, char *charset, char **p)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (str[i])
	{
		k = 0;
		while (str[i] && is_a_sep(str[i], charset))
			i++;
		if (!str[i])
			break ;
		p[j] = malloc(sizeof(char) * (countlen(&str[i], charset) + 1));
		if (!p[j])
			return (NULL);
		while (str[i] && !is_a_sep(str[i], charset))
			p[j][k++] = str[i++];
		p[j++][k] = '\0';
	}
	p[j] = NULL;
	return (p);
}

char	**ft_split(char *str, char *charset)
{
	char	**p;

	p = malloc(sizeof(char *) * (countword(str, charset) + 1));
	if (!p)
		return (NULL);
	p = copy(str, charset, p);
	return (p);
}
