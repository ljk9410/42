/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:55:27 by jung-lee          #+#    #+#             */
/*   Updated: 2020/11/10 13:34:35 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			count;
	size_t			num;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	count = 0;
	num = n;
	while (n > 0 && *c1 != '\0')
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
		c1++;
		c2++;
		count++;
		n--;
	}
	if (n == 0 || num == count)
		return (0);
	return (*c1 - *c2);
}
