/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:08:08 by jung-lee          #+#    #+#             */
/*   Updated: 2020/11/07 17:03:30 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*cpy_dest;
	unsigned char	*cpy_src;

	cpy_dest = (unsigned char*)dest;
	cpy_src = (unsigned char*)src;
	while (n--)
	{
		if (*cpy_src != (unsigned char)c)
		{
			*cpy_dest = *cpy_src;
			if (n)
			{
				cpy_dest++;
				cpy_src++;
			}
		}
		else
		{
			*cpy_dest = *cpy_src;
			return (cpy_dest + 1);
		}
	}
	return (NULL);
}
