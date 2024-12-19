/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:20:56 by moel-idr          #+#    #+#             */
/*   Updated: 2024/12/02 16:23:48 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	printaddr(void *ptr)
{
	int				len;
	int				wr;
	char			*base;
	unsigned long	nbr;

	len = 0;
	nbr = (unsigned long)ptr;
	base = "0123456789abcdef";
	if (nbr > 15)
		len += printaddr((void *)(nbr / 16));
	wr = write(1, &base[nbr % 16], 1);
	if (wr == -1)
		return (-1);
	len += 1;
	return (len);
}

int	ft_print_ptr(void *p)
{
	int	len;

	write(1, "0x", 2);
	len = printaddr(p);
	len = len + 2;
	return (len);
}
