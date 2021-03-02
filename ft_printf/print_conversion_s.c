/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:06:51 by jung-lee          #+#    #+#             */
/*   Updated: 2021/03/02 15:43:10 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_precision(int len)
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

static int	check_width(int len)
{
	int	check_w;

	if (g_opts.width <= len)
		check_w = 0;
	else
		check_w = 1;
	return (check_w);
}

static void	print_output(char *str, int check_p, int check_w, int len)
{
	if (g_opts.no_options == 1)
		ft_putstr(str);
	else if (check_p == 1 && check_w == 0)
		ft_putstr(str);
	else if (check_p == 1 && check_w == 1)
		ft_putstr_width(str, len);
	else if (check_p == 2)
		print_space(0);
	else if (check_p == 3 && check_w == 0)
		ft_putstr_precision(str);
	else if (check_p == 3 && check_w == 1)
		ft_putstr_width(str, g_opts.precision);
	else if (check_p == 4 && check_w == 0)
		ft_putstr(str);
	else if (check_p == 4 && check_w == 1)
	{
		g_opts.precision = len;
		ft_putstr_width(str, len);
	}
}

void		print_conversion_s(va_list ap)
{
	char	*str;
	int		len;
	int		check_p;
	int		check_w;

	check_p = 0;
	check_w = 0;
	handle_wp_star(ap);
	str = va_arg(ap, char *);
	len = ft_strlen(str);
	check_p = check_precision(len);
	check_w = check_width(len);
	print_output(str, check_p, check_w, len);
}
