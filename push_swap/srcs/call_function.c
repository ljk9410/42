/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:38:34 by jung-lee          #+#    #+#             */
/*   Updated: 2021/06/28 14:46:08 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		call_ra(t_struct *head_a, int *ra_cnt)
{
	ra(head_a);
	(*ra_cnt)++;
}

void		call_rb(t_struct *head_b, int *rb_cnt)
{
	rb(head_b);
	(*rb_cnt)++;
}

void		call_pa(t_struct *head_a, t_struct *head_b, int *pa_cnt)
{
	pa(head_a, head_b);
	(*pa_cnt)++;
}

void		call_pb(t_struct *head_a, t_struct *head_b, int *pb_cnt)
{
	pb(head_a, head_b);
	(*pb_cnt)++;
}

