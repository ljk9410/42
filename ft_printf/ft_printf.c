/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:51:27 by jung-lee          #+#    #+#             */
/*   Updated: 2021/02/23 14:48:21 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
    va_list     ap;
    int         i;

    va_start(ap, format);
    i = 0;
    while (format[i] != 0)
    {
        if (format[i] != '%')
            write(1, &format[i], 1);
        else
        {
        	init_struct();
        	i = check_options(format, i + 1);
			check_conversion(ap);
        }
        i++;
    }
    va_end(ap);
    return (0);
}
