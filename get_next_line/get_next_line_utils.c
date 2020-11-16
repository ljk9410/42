/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:45:12 by jung-lee          #+#    #+#             */
/*   Updated: 2020/11/16 16:59:27 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*ptr;
	int		i;

	size = ft_strlen(s);
	if (!(ptr = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	char	*result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(result = (char *)malloc(sizeof(char) * (len1 + len2) + 1)))
		return (NULL);
	i = 0;
	while (i < len1)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
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
