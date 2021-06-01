/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:00:37 by jung-lee          #+#    #+#             */
/*   Updated: 2021/06/01 17:50:12 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi(const char *str)
{
	int	n;
	int	sign;

	while (*str == '\n' || *str == '\t' || *str == ' '
			|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	sign = 1;
	if (*str == '+')
	{
		sign = 1;
		str++;
	}
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n = 10 * n + *str - '0';
		str++;
	}
	return (sign * n);
}
