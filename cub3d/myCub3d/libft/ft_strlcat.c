/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:22:58 by jung-lee          #+#    #+#             */
/*   Updated: 2020/11/10 13:13:04 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dest_len < size)
	{
		while (*dest != '\0')
			dest++;
		i = 0;
		while (i < size - dest_len - 1 && *src != '\0')
		{
			*dest = *src;
			dest++;
			src++;
			i++;
		}
		*dest = '\0';
		return (dest_len + src_len);
	}
	return (size + src_len);
}
