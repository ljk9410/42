/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:38:27 by jung-lee          #+#    #+#             */
/*   Updated: 2021/02/23 15:06:13 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_conversion_d(va_list ap)
{
	int 	d;
	char	*d_str;

	d = va_arg(ap, int);
	d_str = ft_itoa(d);
	ft_putstr(d_str);
}
