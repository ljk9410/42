/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:27:38 by jung-lee          #+#    #+#             */
/*   Updated: 2021/02/24 11:27:47 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    	check_conversion(va_list ap)
{
	if (g_opts.type == 'c')
		print_conversion_c(ap);
	if (g_opts.type == 's')
		print_conversion_s(ap);
    if (g_opts.type == 'd')
        print_conversion_d(ap);
    /*if (g_opts.type == 'i')
        print_conversion_i();
    if (g_opts.type == 'u')
        print_conversion_u();
    if (g_opts.type == 'x')
        print_conversion_x();
    if (g_opts.type == 'X')
        print_conversion_X();
    if (g_opts.type == '%')
        print_conversion_percent(); */
}
