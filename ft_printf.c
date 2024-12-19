/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:15:03 by moel-idr          #+#    #+#             */
/*   Updated: 2024/12/04 21:39:28 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	percent_check(va_list args, char sep)
{
	if (sep == '%')
		return (write(1, "%", 1));
	else if (sep == 'c')
	{
		ft_putchar((char)va_arg(args, int));
		return (1);
	}
	else if (sep == 's')
		return (print_str(va_arg(args, char *)));
	else if (sep == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (sep == 'd' || sep == 'i')
		return (print_int(va_arg(args, int)));
	else if (sep == 'u')
		return (print_u_int((unsigned long)va_arg(args, unsigned int)));
	else if (sep == 'x' || sep == 'X')
		return (print_hex(va_arg(args, unsigned long), sep));
	else
		return (write(1, &sep, 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	if (!format || write(1, NULL, 0) == -1)
		return (-1);
	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			len = len + percent_check(args, format[i]);
		}
		else
			len = len + write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
