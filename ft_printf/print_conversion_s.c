/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:06:51 by jung-lee          #+#    #+#             */
/*   Updated: 2021/02/24 15:18:33 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_precision(int len)
{
	int check_p;

	if (g_opts.precision < 0)
		check_p = 1;
	if ((g_opts.precision == 0 || g_opts.no_precision == 1))
		check_p = 2;
	if (g_opts.precision > 0 && g_opts.precision < len)
		check_p = 3;
	if (g_opts.precision > 0 && g_opts.precision >= len)
		check_p = 4;
	return (check_p);
}

int		check_width(int len)
{
	int	check_w;

	if (g_opts.width <= len)
		check_w = 0;
	else
		check_w = 1;
	return (check_w);
}

void	print_conversion_s(va_list ap)
{
	char	*str;
	int		len;
	int		check_p;
	int		check_w;

	handle_width_star(ap);
	handle_precision_star(ap);
	str = va_arg(ap, char *);
	len = ft_strlen(str);
	check_p = check_precision(len);
	check_w = check_width(len);
}