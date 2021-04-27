/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:49:24 by jung-lee          #+#    #+#             */
/*   Updated: 2020/11/07 17:32:39 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *p1, const void *p2, size_t n)
{
	unsigned char	*compare_p1;
	unsigned char	*compare_p2;

	if (n == 0)
		return (0);
	compare_p1 = (unsigned char *)p1;
	compare_p2 = (unsigned char *)p2;
	while (n--)
	{
		if (*compare_p1 != *compare_p2)
			return (*compare_p1 - *compare_p2);
		if (n)
		{
			compare_p1++;
			compare_p2++;
		}
	}
	return (*compare_p1 - *compare_p2);
}
