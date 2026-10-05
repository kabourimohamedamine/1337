#ifndef UTILS_H
# define UTILS_H

# include "utils.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putnbr(int n);
void	ft_putstr(char const *s);
void	ft_putchar(char c);
void	ft_putnbr_u(unsigned int n);
void	ft_hex(int n);
void	ft_hex_up(int n);
void	ft_pointer(void *n);
void	choise(char str, va_list *par);
void	flags(char **c, va_list *par);
void	minus(char **c, va_list *par);
int		ft_atoi(char **c);
int		ft_ult_len(char c, va_list par);
int		ft_len(char *a);
int		ft_len_unum(unsigned int a);
int		ft_len_num(int a);
int		ft_len_hex(int a);
void	zeros(char **c, va_list *par);
void	points(char **c, va_list *par);
#endif
