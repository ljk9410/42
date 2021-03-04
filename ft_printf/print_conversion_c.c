/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_c.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:31:51 by jung-lee          #+#    #+#             */
/*   Updated: 2021/03/04 16:01:10 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_conversion_c(va_list ap)
{
	int		c;
	int		len;

	handle_wp_star(ap);
	c = va_arg(ap, int);
	len = 1;
	if (g_opts.minus == 0)
	{
		print_space(len);
		write(1, &c, 1);
	}
	else
	{
		write(1, &c, 1);
		print_space(len);
	}
	g_opts.result++;
}
