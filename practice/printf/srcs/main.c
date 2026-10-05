#include "../includes/utils.h"

int	ft_printf(const char *str, ...)
{
	va_list	par;

	va_start(par, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			flags(&str, &par);
		}
		else
			write(1, str, 1);
		str++;
	}
	va_end(par);
	return (1);
}

void	flags(char **c, va_list *par)
{
	if (**c == '-')
		minus(c, par);
	else if (**c == '0')
		zeros(c, par);
	else if (**c == '.')
		points(c, par);
	else
		choise(**c, par);
}

void	points(char **c, va_list *par)
{
	int	i;
	int	j;

	(*c)++;
	i = ft_atoi(c);
	j = ft_ult_len(**c, *par);
	if (**c != 's')
	{
		while (j < i)
		{
			write(1, "0", 1);
			j++;
		}
		choise(**c, par);
	}
	else
		write(1, va_arg(*par, char *), i);
}

void	zeros(char **c, va_list *par)
{
	int	i;
	int	j;

	(*c)++;
	i = ft_atoi(c);
	j = ft_ult_len(**c, *par);
	while (j < i)
	{
		write(1, "0", 1);
		j++;
	}
	choise(**c, par);
}

void	minus(char **c, va_list *par)
{
	int	i;
	int	j;

	(*c)++;
	i = ft_atoi(c);
	j = ft_ult_len(**c, *par);
	choise(**c, par);
	while (j < i)
	{
		write(1, " ", 1);
		j++;
	}
}
