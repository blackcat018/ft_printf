/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:14:25 by moel-idr          #+#    #+#             */
/*   Updated: 2024/11/28 16:09:04 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		print_str(char *str);
int		print_int(int n);
int		print_hex(unsigned int nbr, char up);
int		ft_print_ptr(void *p);
void	ft_putchar(char c);
int		print_u_int(unsigned int n);
int		ft_printf(const char *format, ...);

#endif