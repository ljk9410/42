/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:01:56 by jung-lee          #+#    #+#             */
/*   Updated: 2021/03/04 15:57:51 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_wp_star(va_list ap)
{
	if (g_opts.width_star == 1)
	{
		g_opts.width = va_arg(ap, int);
		if (g_opts.width < 0)
		{
			g_opts.minus = 1;
			g_opts.width *= -1;
		}
	}
	if (g_opts.precision_star == 1)
		g_opts.precision = va_arg(ap, int);
}

void		print_space(int len)
{
	int i;

	if (g_opts.width > 0)
	{
		i = g_opts.width - len;
		while (i)
		{
			write(1, " ", 1);
			g_opts.result++;
			i--;
		}
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		g_opts.result++;
		i++;
	}
}

void	ft_putstr_precision(char *str)
{
	int i;

	i = 0;
	if (g_opts.precision < 0)
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			g_opts.result++;
			i++;
		}
	}
	else
	{
		while (i < g_opts.precision)
		{
			write(1, &str[i], 1);
			g_opts.result++;
			i++;
		}
	}
}

void	ft_putstr_width(char *str, int len)
{
	if (g_opts.minus == 0)
	{
		print_space(len);
		ft_putstr_precision(str);
	}
	else
	{
		ft_putstr_precision(str);
		print_space(len);
	}
}
