/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiskim <kiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 16:18:37 by kiskim            #+#    #+#             */
/*   Updated: 2021/08/28 16:19:22 by kiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int     ft_atoi(const char *str);
void    ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *str);

#endif
