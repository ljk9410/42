/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:40:51 by jung-lee          #+#    #+#             */
/*   Updated: 2020/11/08 14:12:21 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	int_len(long long n)
{
	long long	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = n * -1;
	}
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	long long	size;
	long long	num;
	char		*result;
	int			sign;

	num = (long long)n;
	size = int_len(num);
	sign = 1;
	if (!(result = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	if (num < 0)
	{
		num = num * -1;
		sign = -1;
	}
	result[0] = '0';
	result[size--] = '\0';
	while (num != 0)
	{
		result[size--] = num % 10 + '0';
		num = num / 10;
	}
	if (sign == -1)
		result[0] = '-';
	return (result);
}
