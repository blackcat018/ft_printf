/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:52:32 by moel-idr          #+#    #+#             */
/*   Updated: 2024/11/28 16:02:19 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_u_nbr(unsigned  int n)
{
	if (n >= 10)
	{
		ft_put_u_nbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}
static int num_len(unsigned int n)
{
	unsigned int i;
	int len;

	i = n;
	len = 0;
	if(n == 0)
		return(1);
	while(i > 0)
	{
		i = i / 10;
		len++;
	}
	return (len);
}
int print_u_int(unsigned int n)
{
	int print_len;

	print_len = num_len(n);
	ft_put_u_nbr(n);
	return (print_len);
}