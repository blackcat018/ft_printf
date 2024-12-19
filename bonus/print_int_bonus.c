/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:10:21 by moel-idr          #+#    #+#             */
/*   Updated: 2024/12/04 16:35:55 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		ft_putnbr(n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

static int	num_len(int n)
{
	int	i;
	int	len;

	i = n;
	len = 0;
	if (n < 0)
	{
		len++;
		i = -i;
	}
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	while (i > 0)
	{
		i = i / 10;
		len++;
	}
	return (len);
}

int	print_int(int n, t_flags flag)
{
	int	print_len;

	print_len = num_len(n);
	if (n >= 0)
	{
		if (flag.plus && n >= 0)
		{
			write(1, "+", 1);
			print_len++;
		}
		else if (flag.space && !flag.plus)
		{
			write(1, " ", 1);
			print_len++;
		}
	}
	ft_putnbr(n);
	return (print_len);
}
