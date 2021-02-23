/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:44:55 by jung-lee          #+#    #+#             */
/*   Updated: 2021/02/23 15:07:26 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h> // 지워야 하는 헤더
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct      s_options
{
    int             minus;
    int             zero;
    int             width_star;
    int             width;
    int             dot;
    int             precision;
    int             precision_star;
    int             type;
}                   t_options;
t_options           g_opts;
int                 ft_printf(const char *format, ...);
int                 is_conversion(char c);
int                 check_options(const char *format, int i);
void                init_struct();
void                check_conversion(va_list ap);
void				print_conversion_c(va_list ap);
void				print_conversion_s(va_list ap);
void				print_conversion_d(va_list ap);
size_t	            ft_strlen(const char *str);
int	                ft_atoi(const char *str);
char	            *ft_strchr(const char *str, int c);
char		        *ft_itoa(int n);
void				ft_putstr(char *str);
#endif
