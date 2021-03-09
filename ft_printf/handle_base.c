/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:43:15 by jung-lee          #+#    #+#             */
/*   Updated: 2021/03/09 15:44:50 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	num_len(long long n)
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

long long	num_len_hex(long long n)
{
	long long	len;

	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

char		*itoa_basic(long long n, long long size)
{
	int			sign;
	char		*result;

	sign = 1;
	if (!(result = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	if (n < 0)
	{
		n = n * -1;
		sign = -1;
	}
	if (n == 0)
		result[0] = '0';
	result[size--] = '\0';
	while (n)
	{
		result[size--] = n % 10 + '0';
		n = n / 10;
	}
	if (sign == -1)
		result[0] = '-';
	return (result);
}

char		*itoa_hex(long long n, long long size, char type)
{
	char		*result;
	long long	mod;

	if (!(result = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	if (n == 0)
		result[0] = '0';
	result[size--] = '\0';
	while (n)
	{
		mod = n % 16;
		if (mod < 10)
			result[size--] = 48 + mod;
		else
		{
			if (type == 'x')
				result[size--] = 97 + (mod - 10);
			if (type == 'X')
				result[size--] = 65 + (mod - 10);
		}
		n = n / 16;
	}
	return (result);
}

char		*ft_itoa_base(long long n, int base, char type)
{
	char		*result;
	long long	size;

	result = 0;
	if (base == 10)
	{
		size = num_len(n);
		result = itoa_basic(n, size);
	}
	if (base == 16)
	{
		size = num_len_hex(n);
		result = itoa_hex(n, size, type);
	}
	return (result);
}
