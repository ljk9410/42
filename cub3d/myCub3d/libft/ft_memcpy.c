/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:42:00 by jung-lee          #+#    #+#             */
/*   Updated: 2020/11/07 16:54:49 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned char *t_dest;
	unsigned char *t_src;

	if (!dest && !src)
		return (dest);
	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	while (n--)
	{
		*t_dest = *t_src;
		if (n)
		{
			t_dest++;
			t_src++;
		}
	}
	return (dest);
}
