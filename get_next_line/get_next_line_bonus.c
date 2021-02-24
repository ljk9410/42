/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:32:17 by jung-lee          #+#    #+#             */
/*   Updated: 2020/12/18 15:32:58 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int		put_new_line(char **backup, char **line, int fd)
{
	char		*temp;
	int			i;

	i = 0;
	while (backup[fd][i] != '\n' && backup[fd][i] != '\0')
		i++;
	if (backup[fd][i] == '\n')
	{
		*line = ft_substr(backup[fd], 0, i);
		temp = ft_strdup(&(backup[fd][i + 1]));
		free(backup[fd]);
		backup[fd] = temp;
	}
	else
	{
		*line = ft_strdup(backup[fd]);
		free(backup[fd]);
		backup[fd] = NULL;
		return (0);
	}
	return (1);
}

static int		get_result(char **backup, char **line, ssize_t rd_size, int fd)
{
	if (rd_size < 0)
		return (-1);
	if (rd_size == 0 && backup[fd] == NULL)
	{
		*line = ft_strdup("");
		free(backup[fd]);
		backup[fd] = NULL;
		return (0);
	}
	return (put_new_line(backup, line, fd));
}

int				get_next_line(int fd, char **line)
{
	static char	*backup[255];
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	ssize_t		rd_size;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((rd_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd_size] = '\0';
		if (!backup[fd])
			backup[fd] = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(backup[fd], buf);
			free(backup[fd]);
			backup[fd] = temp;
		}
		if (ft_strchr(backup[fd], '\n'))
			break ;
	}
	return (get_result(backup, line, rd_size, fd));
}