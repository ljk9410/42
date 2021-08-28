/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiskim <kiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 16:18:32 by kiskim            #+#    #+#             */
/*   Updated: 2021/08/28 16:18:48 by kiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

char	*char_to_binary_str(char c)
{
	char	*binary_str;
	int		i;

	binary_str = (char *)malloc(sizeof(char) * 9);
	i = 0;
	while (i < 8)
		binary_str[i++] = '0';
	binary_str[i] = '\0';
	i = 7;
	while (c / 2 != 0)
	{
		binary_str[i--] = (c % 2) + '0';
		c = c / 2;
	}
	binary_str[i] = (c % 2) + '0';
	return (binary_str);
}

void	send_message_to_server(int server_pid, char *message)
{
	int		i;
	int		j;
	char	*binary_str;
	int		len;

	len = ft_strlen(message);
	i = 0;
	while (i <= len)
	{
		binary_str = char_to_binary_str(message[i]);
		j = 0;
		while (binary_str[j])
		{
			usleep(100);
			if (binary_str[j] == '0')
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			j++;
		}
		free(binary_str);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;

	if (argc != 3)
		return (-1);
	server_pid = ft_atoi(argv[1]);
	if (server_pid > 32768)
	{
		write(1, "PID RANGE IS OVER\n", 18);
		exit(0);
	}
	send_message_to_server(server_pid, argv[2]);
	return (0);
}
