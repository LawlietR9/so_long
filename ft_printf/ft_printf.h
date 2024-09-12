#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

int	ft_printf(const char *format, ...);
int ft_putchar(char c);
int ft_putstr(char *str);
int ft_putnbr(int n);
int ft_putnbr_base(unsigned int n, char *base);
int ft_putptr(unsigned long long n);
int specificater(va_list args, const char c);

#endif