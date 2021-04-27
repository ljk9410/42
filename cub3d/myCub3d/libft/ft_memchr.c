/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:14:53 by jung-lee          #+#    #+#             */
/*   Updated: 2020/10/17 16:19:49 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int v, size_t n)
{
	unsigned char	*start;
	unsigned char	find;

	start = (unsigned char*)ptr;
	find = (unsigned char)v;
	while (n--)
	{
		if (*start != find)
			start++;
		else
			return (start);
	}
	return (NULL);
}
