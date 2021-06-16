/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:29:29 by jung-lee          #+#    #+#             */
/*   Updated: 2021/06/01 17:40:17 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_struct
{
	int				value;
	struct s_struct	*next;
}					t_struct;

int					ft_atoi(const char *str);
void				add_lst_back(t_struct *node, int n);
t_struct			*find_lst_last(t_struct *node);
void				pa(t_struct *head_a, t_struct *head_b);
void				pb(t_struct *head_a, t_struct *head_b);
#endif
