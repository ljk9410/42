/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 17:10:57 by jung-lee          #+#    #+#             */
/*   Updated: 2020/10/28 14:53:43 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	result;

	result = ft_strlen(src);
	if (n > 1)
	{
		n = n - 1;
		while (n-- && *src != '\0')
		{
			*dest++ = *src++;
		}
		*dest = '\0';
	}
	return (result);
}
