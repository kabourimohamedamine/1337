#include "../includes/utils.h"

int	ft_atoi(char **c)
{
	int	res;

	res = 0;
	while (**c >= '0' && **c <= '9')
	{
		res = res * 10 + (**c - '0');
		(*c)++;
	}
	return (res);
}

int	ft_ult_len(char c, va_list par)
{
	if (c == 's')
		return (ft_len(va_arg(par, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_len_num(va_arg(par, int)));
	else if (c == 'u')
		return (ft_len_unum(va_arg(par, int)));
	else if (c == 'x' || c == 'X')
		return (ft_len_hex(va_arg(par, int)));
	else if (c == 'p')
		return (ft_len_hex(va_arg(par, unsigned long)) + 4);
	return (1);
}

void	choise(char str, va_list *par)
{
	if (str == 'c')
		ft_putchar(va_arg(*par, int));
	else if (str == 's')
		ft_putstr(va_arg(*par, char *));
	else if (str == 'd' || str == 'i')
		ft_putnbr(va_arg(*par, int));
	else if (str == 'u')
		ft_putnbr_u(va_arg(*par, unsigned int));
	else if (str == 'p')
		ft_pointer(va_arg(*par, void *));
	else if (str == 'x')
		ft_hex(va_arg(*par, int));
	else if (str == 'X')
		ft_hex_up(va_arg(*par, int));
	else if (str == '%')
		write(1, "%", 1);
	else
		write(1, "error", 5);
}

int	ft_len_num(int a)
{
	int	i;

	i = 1;
	while (a / 10 != 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

int	ft_len_unum(unsigned int a)
{
	int	i;

	i = 1;
	while (a / 10 != 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}
