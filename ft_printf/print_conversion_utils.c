/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:01:56 by jung-lee          #+#    #+#             */
/*   Updated: 2021/02/24 14:12:35 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_width_star(va_list ap)
{
	if (g_opts.width_star == 1)
	{
		g_opts.width = va_arg(ap, int);
		if (g_opts.width < 0)
		{
			g_opts.minus = 1;
			g_opts.width *= -1;
		}
	}
}

void		handle_precision_star(va_list ap)
{
	if (g_opts.precision_star == 1)
		g_opts.precision = va_arg(ap, int);
}
