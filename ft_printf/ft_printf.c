/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:51:27 by jung-lee          #+#    #+#             */
/*   Updated: 2021/03/04 16:15:05 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
    va_list     ap; // va_list 선언을 전역변수로 처리하면 어떨까?
    int         i;

	g_opts.result = 0;
    va_start(ap, format);
    i = 0;
    while (format[i] != 0)
    {
        if (format[i] != '%')
		{
            write(1, &format[i], 1);
			g_opts.result++;
		}
		else
        {
        	init_struct();
        	i = check_options(format, i + 1);
			check_conversion(ap);
        }
        i++;
    }
    va_end(ap);
    return (g_opts.result);
}
