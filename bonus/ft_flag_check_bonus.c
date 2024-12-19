/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:25:32 by moel-idr          #+#    #+#             */
/*   Updated: 2024/12/02 21:16:57 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_flags	check_flag(const char **sep, t_flags flag)
{
	while (**sep == ' ' || **sep == '#' || **sep == '+')
	{
		if (**sep == ' ')
			flag.space = 1;
		else if (**sep == '+')
			flag.plus = 1;
		else if (**sep == '#')
			flag.tag = 1;
		*(sep) = *(sep) + 1;
	}
	return (flag);
}
