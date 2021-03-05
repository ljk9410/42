/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_diuxX.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:38:27 by jung-lee          #+#    #+#             */
/*   Updated: 2021/03/05 17:07:23 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_precision(char *str, int len)
{
	int 			check_p;

	if (str[0] == '-')
		len--;
	if (g_opts.precision < 0)
		check_p = 0;
	if (g_opts.precision == 0 || g_opts.no_precision == 1)
	{
		check_p = 1;
		if (str[0] == '0')
			check_p = 4;
	}
	if (g_opts.precision > 0 && g_opts.precision <= len)
		check_p = 2;
	if (g_opts.precision > 0 && g_opts.precision > len)
		check_p = 3;
	return (check_p);
}

static int	check_width(int len)
{
	int				check_w;

	if (g_opts.width <= len)
		check_w = 0;
	else
		check_w = 1;
	return (check_w);
}

static void	print_output(char *num_str, int check_p, int check_w, int len)
{
	if (check_p == 0 && check_w == 0)
		ft_putstr(num_str);
	if (check_p == 0 && check_w == 1)
		ft_putnum_width(num_str, len);
	if (check_p == 1 && check_w == 0)
		ft_putstr(num_str);
	if (check_p == 1 && check_w == 1)
		ft_putnum(num_str, len);
	if (check_p == 2 && check_w == 0)
		ft_putstr(num_str);
	if (check_p == 2 && check_w == 1)
		ft_putnum(num_str, len);
	if (check_p == 3)
	{
		if (num_str[0] == '-')
			ft_putnum_wp_minus(num_str ,len);
		else
			ft_putnum_wp(num_str, len);
	}
	if (check_p == 4)
		print_precision_zero();
}

char		*make_str(va_list ap)
{
	int				num_di;
	unsigned int	num_uxX;
	char			*num_str;

	if (g_opts.type == 'd' || g_opts.type == 'i')
	{
		num_di = va_arg(ap, int);
		num_str = ft_itoa(num_di);
	}
	if (g_opts.type == 'u' || g_opts.type == 'x' || g_opts.type == 'X')
	{
		num_uxX = va_arg(ap, unsigned int);
		if (g_opts.type == 'u')
			num_str = ft_itoa_base(num_uxX, 10, 'c');
		if (g_opts.type == 'x')
			num_str = ft_itoa_base(num_uxX, 16, 'x');
		if (g_opts.type == 'X')
			num_str = ft_itoa_base(num_uxX, 16, 'X');
	}
	return (num_str);
}

void		print_conversion_diuxX(va_list ap)
{
	int				len;
	int 			check_p;
	int				check_w;
	char			*num_str;

	handle_wp_star(ap);
	num_str = make_str(ap);
	len = ft_strlen(num_str);
	check_p = check_precision(num_str, len);
	check_w = check_width(len);
	print_output(num_str, check_p, check_w, len);
	free(num_str);
}
