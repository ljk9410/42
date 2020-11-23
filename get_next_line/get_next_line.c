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

static int	check_new_line(char *backup, char **line)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	if (backup[i] == '\n')
	{
		*line = ft_substr(backup, 0, i);
		temp = ft_strdup(&backup[i + 1]);
		free(backup);
		backup = temp;
	}
	else
	{
		*line = ft_substr(backup, 0, i);
		free(backup);
		return (0);
	}
	return (1);
}

static int	get_result(char *backup, char **line)
{
	if (!check_new_line(backup, line))
		return (0);
	return (1);
}

int			get_next_line(int fd, char **line)
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
			backup = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(backup, buf);
			free(backup);
			backup = temp;
		}
		if (ft_strchr(backup, '\n'))
				break ;
	}
	return (get_result(backup, line));
}
