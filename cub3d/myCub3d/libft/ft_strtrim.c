/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:46:22 by jung-lee          #+#    #+#             */
/*   Updated: 2020/11/10 13:03:14 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	length(char const *s, char const *set)
{
	size_t	front_len;
	size_t	back_len;
	size_t	str_len;

	str_len = ft_strlen(s);
	front_len = 0;
	while (front_len < (str_len - 1) && ft_strchr(set, *s))
	{
		front_len++;
		s++;
	}
	while (*s != '\0')
		s++;
	s--;
	back_len = 0;
	while (back_len < str_len - front_len
			&& ft_strchr(set, *s))
	{
		back_len++;
		s--;
	}
	return (front_len + back_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	trim_len;
	size_t	i;
	size_t	j;
	char	*result;

	trim_len = length(s1, set);
	if (ft_strlen(s1) == trim_len || !ft_strlen(s1))
		return (ft_strdup(""));
	if (!(result = (char *)malloc(sizeof(char) *
					((ft_strlen(s1) - trim_len) + 1))))
		return (NULL);
	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	j = 0;
	while (j < ft_strlen(s1) - trim_len)
	{
		result[j] = s1[i + j];
		j++;
	}
	result[j] = 0;
	return (result);
}
