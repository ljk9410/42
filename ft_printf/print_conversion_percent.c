/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_percent.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:07:56 by jung-lee          #+#    #+#             */
/*   Updated: 2021/03/09 16:08:22 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_conversion_percent(va_list ap)
{
	handle_wp_star(ap);
	if (g_opts.minus == 1)
	{
		write(1, "%", 1);
		print_space(1);
	}
	else
	{
		if (g_opts.zero == 1)
			print_zero(g_opts.width - 1);
		else
			print_space(1);
		write(1, "%", 1);
	}
	g_opts.result++;
}
