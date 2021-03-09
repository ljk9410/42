/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:29:42 by jung-lee          #+#    #+#             */
/*   Updated: 2021/03/09 15:16:29 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_output(char *str)
{
	int			len;

	len = ft_strlen(str);
	if (g_opts.minus == 0)
	{
		print_space(len + 2);
		write(1, "0", 1);
		write(1, "x", 1);
		ft_putstr(str);
	}
	else
	{
		write(1, "0", 1);
		write(1, "x", 1);
		ft_putstr(str);
		print_space(len + 2);
	}
	g_opts.result += 2;
}

static void		print_output_zero(char *str)
{
	if (g_opts.width <= 3)
	{
		write(1, "0", 1);
		write(1, "x", 1);
		ft_putstr(str);
	}
	else
	{
		print_output(str);
		g_opts.result -= 2;
	}
}

static void		print_output_nofit(char *str)
{
	if (ft_strlen(str) == 1)
		print_output_zero(str);
	else
	{
		write(1, "0", 1);
		write(1, "x", 1);
		ft_putstr(str);
	}
	g_opts.result += 2;
}

static void		print_output_null(void)
{
	if (g_opts.width <= 2)
	{
		write(1, "0", 1);
		write(1, "x", 1);
	}
	else
	{
		if (g_opts.minus == 0)
		{
			print_space(2);
			write(1, "0", 1);
			write(1, "x", 1);
		}
		else
		{
			write(1, "0", 1);
			write(1, "x", 1);
			print_space(2);
		}
	}
	g_opts.result += 2;
}

void			print_conversion_p(va_list ap)
{
	long long	ptr;
	char		*ptr_str;
	int			len;

	handle_wp_star(ap);
	ptr = va_arg(ap, long long);
	if ((void *)ptr == NULL && g_opts.dot == 1)
		print_output_null();
	else
	{
		ptr_str = ft_itoa_base(ptr, 16, 'x');
		len = ft_strlen(ptr_str);
		if (g_opts.width < (len + 2))
			print_output_nofit(ptr_str);
		else
			print_output(ptr_str);
		free(ptr_str);
	}
}
