#include "utils.h"
#include <stdarg.h>
#include <unistd.h>
int	ft_printf(const char *str, ...)
{
	va_list	par;
	int		i;

	i = 0;
	va_start(par, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
				ft_putchar(va_arg(par, int));
			else if (str[i] == 's')
				ft_putstr(va_arg(par, char *));
			else if (str[i] == 'd' || str[i] == 'i')
				ft_putnbr(va_arg(par, int));
			else if (str[i] == 'u')
				ft_putnbr_u(va_arg(par, unsigned int));
			else if (str[i] == 'p')
				ft_pointer(va_arg(par, void *));
			else if (str[i] == 'x')
				ft_hex(va_arg(par, int));
			else if (str[i] == 'X')
				ft_Hex(va_arg(par, int));
			else if (str[i] == '%')
				write(1, "%", 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(par);
	return (1);
}
#include <stdio.h>

int	main(void)
{
	char *a;
	a = NULL;
	ft_printf("%p\n", a);
	printf("%p", a);
}