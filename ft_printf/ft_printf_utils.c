/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenito <kenito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:13:41 by kenito            #+#    #+#             */
/*   Updated: 2023/11/01 19:13:41 by kenito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
	{
		i = ft_putstr("(null)");
		return (i);
	}
	i = 0;
	while (str[i])
		i += ft_putchar(str[i]);
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == INT_MIN)
	{
		i += ft_putstr("-2147483648");
		return (i);
	}
	if (n < 0)
	{
		i += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		i += ft_putnbr(n / 10);
	i += ft_putchar(n % 10 + '0');
	return (i);
}

int	ft_putnbr_base(unsigned int n, char *base)
{
	int		i;
	size_t	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	i = 0;
	if (n >= base_len)
		i += ft_putnbr_base(n / base_len, base);
	i += ft_putchar(base[n % base_len]);
	return (i);
}

int	ft_putptr(unsigned long long n)
{
	int		i;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	if (n >= 16)
		i += ft_putptr(n / 16);
	i += ft_putchar(base[n % 16]);
	return (i);
}

// #include <stdio.h>
// int main()
// {
//     int x = -123;
//     int i = ft_putnbr(x);
//     printf("\n");
//     printf("%d", i);
// }