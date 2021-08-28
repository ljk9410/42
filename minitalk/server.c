/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiskim <kiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 16:18:42 by kiskim            #+#    #+#             */
/*   Updated: 2021/08/28 16:18:52 by kiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

char    get_char_from_binary(char *binary_str)
{
    char    c;

    c = (binary_str[0] - '0') * 128
        + (binary_str[1] - '0') * 64 
        + (binary_str[2] - '0') * 32
        + (binary_str[3] - '0') * 16
        + (binary_str[4] - '0') * 8
        + (binary_str[5] - '0') * 4
        + (binary_str[6] - '0') * 2
        + (binary_str[7] - '0') * 1;
    return (c);
}

void    write_message(char *binary_str)
{
    char    c;
    static char buffer[101];
    static int  i;
    static int  end;

    c = get_char_from_binary(binary_str);
    buffer[i++] = c;
    if (c == '\0' || i == 100)
    {
        if (c == '\0')
            end++;
        if (i == 100)
            buffer[i] = '\0';
        write(1, buffer, ft_strlen(buffer));
        if (end == 1)
        {
            write(1, "\n", 1);
            end = 0;
        }
        i = 0;
    }
}

void    sig_handler(int signo)
{
    static char binary_str[9];
    static int  i;

	if (signo == SIGUSR1)
        binary_str[i++] = '0';
    else
        binary_str[i++] = '1';
    if (i == 8)
    {
        binary_str[i] = '\0';
        write_message(binary_str);
        i = 0;
    }
}
 
int     main()
{
    write(1, "Server PID: ", 12);
    ft_putnbr_fd(getpid(), 1);
    write(1, "\n", 1);
    signal(SIGUSR1, (void *)sig_handler);
    signal(SIGUSR2, (void *)sig_handler);
    while(1)
        pause();
    return (0);
}
