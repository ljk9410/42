/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:58:18 by jung-lee          #+#    #+#             */
/*   Updated: 2021/03/02 15:09:47 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	const char *temp;

	temp = str;
	while (*temp != '\0')
	{
		temp++;
	}
	return (temp - str);
}

char	*ft_strchr(const char *str, int c)
{
	char	*s;

	s = (char *)str;
	while (*s != '\0')
	{
		if (*s == (char)c)
			return (s);
		else
			s++;
	}
	if (*s == (char)c)
		return (s);
	return (0);
}

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
