#include "utils.h"
#include <unistd.h>

void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb <= 9)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}

void	ft_putstr(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putnbr_u(unsigned int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb <= 9)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr_u(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}
void	ft_hex(int n)
{
	char	a[] = "0123456789abcdef";
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb <= 16)
		ft_putchar(nb + '0');
	else
	{
		ft_hex(nb / 16);
		ft_putchar(a[(nb % 16)]);
	}
}
void	ft_Hex(int n)
{
	char	a[] = "0123456789ABCDEF";
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb <= 16)
		ft_putchar(nb + '0');
	else
	{
		ft_hex(nb / 16);
		ft_putchar(a[(nb % 16)]);
	}
}
void	ft_print_memory(unsigned long n)
{
	char	a[] = "0123456789abcdef";

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
	unsigned long nb = (unsigned long)n;
	write(1, "0x", 2);
	ft_print_memory(nb);
}