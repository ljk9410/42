/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:51:27 by jung-lee          #+#    #+#             */
/*   Updated: 2021/03/09 15:28:53 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		no_conversion(const char *format, int i)
{
	while (format[i] != '\0' && format[i] != ' ')
	{
		if (ft_strchr("csduixXp%", format[i]))
			return (1);
		i++;
	}
	return (-1);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;

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
			if (no_conversion(format, i + 1) == -1)
				return (-1);
			init_struct();
			i = check_options(format, i + 1);
			check_conversion(ap);
		}
		i++;
	}
	va_end(ap);
	return (g_opts.result);
}
