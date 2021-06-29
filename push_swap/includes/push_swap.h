/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:29:29 by jung-lee          #+#    #+#             */
/*   Updated: 2021/06/29 13:40:15 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

typedef struct		s_struct
{
	int				value;
	struct s_struct	*next;
}					t_struct;
long long			ft_atoi(const char *str);
void				add_lst_back(t_struct *node, int n);
t_struct			*find_lst_last(t_struct *node);
int					size_of_list(t_struct *list);
int					error_check(int argc, char **argv);
int					write_error(void);
void				pa(t_struct *head_a, t_struct *head_b);
void				pb(t_struct *head_a, t_struct *head_b);
void				sa(t_struct *head_a);
void				sb(t_struct	*head_b);
void				ss(t_struct *head_a, t_struct *head_b);
void				ra(t_struct *head_a);
void				rb(t_struct	*head_b);
void				rr(t_struct *head_a, t_struct *head_b);
void				rra(t_struct *head_a);
void				rrb(t_struct *head_b);
void				rrr(t_struct *head_a, t_struct *head_b);
void				a_to_b(t_struct *head_a, t_struct *head_b, int n);
void				b_to_a(t_struct *head_a, t_struct *head_b, int n);
int					check_pivot(t_struct *node, int len);
void				quick_sort(int *arr, int start, int end);
int					get_partition(int *arr, int start, int end);
int					*fill_arr(t_struct *node, int *arr, int len);
void				call_ra(t_struct *head_a, int *ra_cnt);
void				call_rb(t_struct *head_b, int *rb_cnt);
void				call_pa(t_struct *head_a, t_struct *head_b, int *pa_cnt);
void				call_pb(t_struct *head_a, t_struct *head_b, int *pb_cnt);
#endif
