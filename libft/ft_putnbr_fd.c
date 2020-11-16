/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:41:10 by jung-lee          #+#    #+#             */
/*   Updated: 2020/11/08 13:59:06 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		numdigit(long long n)
{
	long long	digit;

	digit = 1;
	n = n / 10;
	while (n > 0)
	{
		n = n / 10;
		digit = digit * 10;
	}
	return (digit);
}

void			putnum(long long num, int fd)
{
	long long	digit;
	long long	n;
	char		c;
	long long	i;

	digit = numdigit(num);
	i = num;
	while (i > 0)
	{
		n = num / digit;
		c = (char)n + '0';
		write(fd, &c, 1);
		num = num % digit;
		digit = digit / 10;
		i = i / 10;
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	long long	num;

	num = (long long)n;
	if (num < 0)
	{
		num = num * -1;
		write(fd, "-", 1);
	}
	else if (n == 0)
		write(fd, "0", 1);
	putnum(num, fd);
}
