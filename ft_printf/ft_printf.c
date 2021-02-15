/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:51:27 by jung-lee          #+#    #+#             */
/*   Updated: 2021/02/15 20:32:00 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h> // 지워야 되는 헤더

int     ft_printf(const char *format, ...)
{
    va_list     ap;
    int         i;
    int         len;
    char        var;
    char        *str;

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
            if (format[i + 1] == 's')
            {
                str = va_arg(ap, char *);
                len = strlen(str);
                for (int j = 0; j < len; j++) // 수정해야 할 부분
                    write(1, &str[j], 1);
                i++;
            }
        }
        i++;
    }
    va_end(ap);
    return (0);
}