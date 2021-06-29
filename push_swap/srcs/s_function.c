/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_function.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:15:59 by jung-lee          #+#    #+#             */
/*   Updated: 2021/06/29 15:53:09 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			sa(t_struct *head_a)
{
	t_struct	*temp_up;
	t_struct	*temp_down;

	if ((head_a->next != NULL) && (head_a->next->next != NULL))
	{
		temp_up = head_a->next;
		temp_down = head_a->next->next;
		head_a->next = temp_down;
		temp_up->next = temp_down->next;
		head_a->next->next = temp_up;
	}
	write(1, "sa\n", 3);
}

void			sb(t_struct *head_b)
{
	t_struct	*temp_up;
	t_struct	*temp_down;

	if ((head_b->next != NULL) && (head_b->next->next != NULL))
	{
		temp_up = head_b->next;
		temp_down = head_b->next->next;
		head_b->next = temp_down;
		temp_up->next = temp_down->next;
		head_b->next->next = temp_up;
	}
	write(1, "sb\n", 3);
}

void			ss(t_struct *head_a, t_struct *head_b)
{
	sa(head_a);
	sb(head_b);
	write(1, "ss\n", 3);
}
