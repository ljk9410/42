/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:27:38 by jung-lee          #+#    #+#             */
/*   Updated: 2021/03/09 15:40:52 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_conversion(va_list ap)
{
	if (g_opts.type == 'c')
		print_conversion_c(ap);
	if (g_opts.type == 's')
		print_conversion_s(ap);
	if (g_opts.type == 'p')
		print_conversion_p(ap);
	if (g_opts.type == 'd' || g_opts.type == 'i' || g_opts.type == 'u'
			|| g_opts.type == 'x' || g_opts.type == 'X')
		print_conversion_diux(ap);
	if (g_opts.type == '%')
		print_conversion_percent(ap);
}
