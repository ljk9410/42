/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:44:55 by jung-lee          #+#    #+#             */
/*   Updated: 2021/02/16 15:09:19 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct      s_options
{
    int             minus;
    int             zero;
    int             star;
    int             width;
    int             dot;
    int             precision;
    int             type;
}                   t_options;
int                 ft_printf(const char *format, ...);
int                 is_conversion(char c);
int                 check_options(const char *format, int i);
size_t	            ft_strlen(const char *str);
char	            *ft_strchr(const char *str, int c);
#endif
