/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:43:35 by jung-lee          #+#    #+#             */
/*   Updated: 2021/03/09 15:35:09 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_conversion(char c)
{
	int		check;

	check = 0;
	if (ft_strchr("cspdiuxX%", (int)c))
		check = 1;
	return (check);
}

int		handle_width_precision(const char *format, int i, int dot)
{
	char	*str;
	int		len;
	int		idx;

	len = 0;
	while (format[i] >= '0' && format[i] <= '9')
	{
		len++;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	idx = i;
	str[len] = 0;
	while (len)
	{
		str[len - 1] = format[--idx];
		len--;
	}
	if (dot == 0)
		g_opts.width = ft_atoi(str);
	else
		g_opts.precision = ft_atoi(str);
	free(str);
	return (i - 1);
}

int		check_options(const char *format, int i)
{
	while (is_conversion(format[i]) == 0)
	{
		if (format[i] == '-')
			g_opts.minus = 1;
		if (g_opts.dot == 0 && format[i] == '0')
			g_opts.zero = 1;
		if (g_opts.dot == 0 && format[i] == '*')
			g_opts.width_star = 1;
		if (format[i] >= '0' && format[i] <= '9' && g_opts.dot == 0)
			i = handle_width_precision(format, i, g_opts.dot);
		if (format[i] == '.')
			g_opts.dot = 1;
		if (format[i] >= '0' && format[i] <= '9' && g_opts.dot == 1)
			i = handle_width_precision(format, i, g_opts.dot);
		if (g_opts.dot == 1 && format[i] == '*')
			g_opts.precision_star = 1;
		i++;
	}
	g_opts.type = format[i];
	if (g_opts.dot == 1 && format[i - 1] == '.')
		g_opts.no_precision = 1;
	if (format[i - 1] == '%')
		g_opts.no_options = 1;
	return (i);
}
