/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_c.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:31:51 by jung-lee          #+#    #+#             */
/*   Updated: 2021/02/23 16:41:45 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_space()
{
	int 	i;

	i = g_opts.width - 1;
	while (i)
	{
		write(1, " ", 1);
		i--;
	}
}

void		print_conversion_c(va_list ap)
{
	int		c;

	if (g_opts.width_star == 1)
	{
		g_opts.width = va_arg(ap, int);
		if (g_opts.width < 0)
		{
			g_opts.minus = 1;
			g_opts.width *= -1;
		}
	}
	c = va_arg(ap ,int);
	if (g_opts.minus == 0)
	{
		print_space();
		write(1, &c, 1);
	}
	else
	{
		print_space();
		write(1, &c, 1);
	}
}
