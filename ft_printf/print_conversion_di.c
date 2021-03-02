/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_di.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:38:27 by jung-lee          #+#    #+#             */
/*   Updated: 2021/03/02 16:39:40 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_precision(int len)
{
	int 	check_p;

	if (g_opts.precision <= 0 || g_opts.no_precision == 1)
		check_p = 1;
	if (g_opts.precision > 0 && g_opts.precision < len)
		check_p = 2;
	if (g_opts.precision > 0 && g_opts.precision >= len)
		check_p = 3;
	return (check_p);
}

static int	check_width(int len)
{
	int		check_w;

	if (g_opts.width < len)
		check_w = 0;
	else
		check_w = 1;
	return (check_w);
}

static void	print_output(char *num_str, int check_p, int check_w, int len)
{
	if (check_p == 1 && check_w == 0)
		ft_putstr(num_str);
	if (check_p == 1 && check_w == 1)
		ft_putnum(num_str, len);
	if (check_p == 2 && check_w == 0)
		ft_putstr(num_str);
	if (check_p == 2 && check_w == 1)
		ft_putnum(num_str, len);
	if (check_p == 3)
		ft_putstr(num_str);
}

void		print_conversion_d(va_list ap)
{

	int 	num;
	int		len;
	int 	check_p;
	int		check_w;
	char	*num_str;

	handle_wp_star(ap);
	num = va_arg(ap, int);
	num_str = ft_itoa(num);
	len = ft_strlen(num_str);
	check_p = check_precision(len);
	check_w = check_width(len);
	print_output(num_str, check_p, check_w, len);
	free(num_str); //ft_itoa() malloc free
}
