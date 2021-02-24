/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_c.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:31:51 by jung-lee          #+#    #+#             */
/*   Updated: 2021/02/24 14:20:11 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_space(void)
{
	int	i;

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

	handle_width_star(ap);
	c = va_arg(ap, int);
	if (g_opts.minus == 0)
	{
		print_space();
		write(1, &c, 1);
	}
	else
	{
		write(1, &c, 1);
		print_space();
	}
}
