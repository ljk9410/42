/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:51:27 by jung-lee          #+#    #+#             */
/*   Updated: 2021/02/15 15:42:03 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{
    va_list     ap;
    int         i;
    char        var;

    va_start(ap, format);
    i = 0;
    while (format[i] != 0)
    {
        if (format[i] != '%')
            write(1, &format[i], 1);
        else
        {
            if (format[i + 1] == 'c')
            {
                var = va_arg(ap, int);
                write(1, &var, 1);
                i++;
            }
        }
        i++;
    }
    return (0);
}