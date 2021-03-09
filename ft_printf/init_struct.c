/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:52:25 by jung-lee          #+#    #+#             */
/*   Updated: 2021/03/09 16:02:45 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(void)
{
	g_opts.minus = 0;
	g_opts.zero = 0;
	g_opts.width_star = 0;
	g_opts.width = 0;
	g_opts.dot = 0;
	g_opts.precision = -1;
	g_opts.no_precision = 0;
	g_opts.precision_star = 0;
	g_opts.type = 0;
	g_opts.no_options = 0;
}
