/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:51:41 by jung-lee          #+#    #+#             */
/*   Updated: 2021/04/29 15:13:02 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	save_resolution(t_info *info, char *str)
{
	char	**res;

	res = ft_split(str, ' ');
	info->win_w = ft_atoi(res[1]);
	info->win_h = ft_atoi(res[2]);
}

void	save_texture(t_info *info, char *str)
{
	char 	**res;

	res = ft_split(str, ' ');
	printf("%s\n", res[1]);
}

int		parsing_map(t_info *info, char *argv)
{
	int		fd;
	int		res;
	char	*str;

	fd = open(argv, O_RDONLY);
	while ((res = get_next_line(fd, &str)) != -1)
	{
		if (str[0] == 'R')
			save_resolution(info, str);
		if (str[0] == 'N' || str[0] == 'S' || str[0] == 'W' || str[0] == 'E')
			save_texture(info, str);
		if (res == 0)
			break ;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_info	info;
	int		temp;

	temp = parsing_map(&info, argv[1]);
	return (0);
}
