/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_percent.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee </var/mail/jung-lee>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:21:52 by jung-lee          #+#    #+#             */
/*   Updated: 2021/02/26 18:46:35 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_conversion_percent(va_list ap)
{
	handle_width_star(ap);
	if (g_opts.precision_star == 1)
		g_opts.precision = va_arg(ap, int);
	if (g_opts.minus == 1)
	{
		write(1, "%", 1);
		print_space(1);
	}
	else
	{
		print_space(1);
		write(1, "%", 1);
	}
}

