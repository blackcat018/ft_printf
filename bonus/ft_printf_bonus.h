/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:14:25 by moel-idr          #+#    #+#             */
/*   Updated: 2024/12/04 16:23:11 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int	tag;
	int	space;
	int	plus;
}		t_flags;

int		print_str(char *str);
int		print_int(int n, t_flags flag);
int		print_hex(unsigned int nbr, const char up, t_flags fg);
int		ft_print_ptr(void *p);
void	ft_putchar(char c);
t_flags	check_flag(const char **sep, t_flags flag);
int		print_u_int(unsigned int n);
int		ft_printf(const char *format, ...);

#endif