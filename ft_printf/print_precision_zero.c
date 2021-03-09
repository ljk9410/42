/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision_zero.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:13:30 by jung-lee          #+#    #+#             */
/*   Updated: 2021/03/09 16:13:43 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_precision_zero(void)
{
	int len;

	len = 0;
	if (g_opts.width > 0)
		len = g_opts.width;
	while (len)
	{
		write(1, " ", 1);
		g_opts.result++;
		len--;
	}
}
