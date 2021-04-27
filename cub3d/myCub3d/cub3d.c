/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:51:41 by jung-lee          #+#    #+#             */
/*   Updated: 2021/04/27 17:11:20 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int		main()
{
	int		fd;
	int		res;
	char	*str;
	
	fd = open("./maps/map.cub", O_RDONLY);
	
	
	while ((res = get_next_line(fd, &str)) != -1)
	{
		printf("%s\n", str);
		if (res == 0)
			break ;
	}
	
	return (0);
}
