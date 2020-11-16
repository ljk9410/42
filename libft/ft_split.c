/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:49:03 by jung-lee          #+#    #+#             */
/*   Updated: 2020/11/08 15:16:38 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		sep_count(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else if (*s != c)
		{
			count++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (count);
}

size_t	sep_word(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != c && *s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		sep;
	int		i;

	sep = sep_count(s, c);
	result = (char **)malloc(sizeof(char *) * (sep + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (sep--)
	{
		while (*s == c && *s != '\0')
			s++;
		if (!(result[i] = ft_substr(s, 0, sep_word(s, c))))
		{
			while (i-- > 0)
				free(result[i]);
			free(result);
			return (NULL);
		}
		s = s + sep_word(s, c);
		i++;
	}
	result[i] = 0;
	return (result);
}
