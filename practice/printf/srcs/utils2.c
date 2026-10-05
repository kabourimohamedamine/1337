#include "../includes/utils.h"

void	ft_hex_up(int n)
{
	char	*a;
	long	nb;

	a = "0123456789ABCDEF";
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb <= 16)
		ft_putchar(a[nb]);
	else
	{
		ft_hex_up(nb / 16);
		ft_putchar(a[(nb % 16)]);
	}
}

void	ft_print_memory(unsigned long n)
{
	char	*a;

	a = "0123456789abcdef";
	if (n < 16)
		ft_putchar(a[n]);
	else
	{
		ft_print_memory(n / 16);
		ft_putchar(a[n % 16]);
	}
}

void	ft_pointer(void *n)
{
	unsigned long	nb;

	nb = (unsigned long)n;
	write(1, "0x", 2);
	ft_print_memory(nb);
}

int	ft_len_hex(int a)
{
	int	i;

	i = 1;
	while (a / 16 != 0)
	{
		a /= 16;
		i++;
	}
	return (i);
}
