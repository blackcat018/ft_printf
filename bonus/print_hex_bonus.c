/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:20:56 by moel-idr          #+#    #+#             */
/*   Updated: 2024/12/04 17:36:58 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	printhexa(unsigned int nbr, char up)
{
	int		len;
	int		wr;
	char	*base;

	len = 0;
	if (up == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr > 15)
		len += printhexa((nbr / 16), up);
	wr = write(1, &base[nbr % 16], 1);
	len += 1;
	return (len);
}

int	print_hex(unsigned int nbr, const char up, t_flags fg)
{
	int	len;
	int	pre;

	len = 0;
	pre = 0;
	if (fg.tag && nbr != 0 && (up == 'x' || up == 'X'))
	{
		if (up == 'X')
			pre += write(1, "0X", 2);
		else if (up == 'x')
			pre += write(1, "0x", 2);
	}
	len = pre + printhexa(nbr, up);
	return (len);
}
