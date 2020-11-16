/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:14:04 by jung-lee          #+#    #+#             */
/*   Updated: 2020/11/16 17:34:02 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*backup;
	char		buf[BUFFER_SIZE + 1];
	char		*temp;

	if (line == NULL || fd < 0)
		return (-1);
	while (read(fd, buf, sizeof(buf)) > 0)
	{
		buf[BUFFER_SIZE] = '\0';
		if (!backup)
			backup = ft_strdup("");
		else
		{
			temp = ft_strjoin(backup, buf);
			free(backup);
			backup = temp;
		}
		if (ft_strchr(backup, '\n'))
				break ;
	}
	return (0);
}
