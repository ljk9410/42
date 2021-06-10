/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_function.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:53:58 by jung-lee          #+#    #+#             */
/*   Updated: 2021/06/10 19:48:31 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			pa(t_struct *head_a, t_struct *head_b)
{
	t_struct	*temp_a;
	t_struct	*temp_b;

	if (head_a->next != NULL)
	{
		temp_a = head_a->next;
		head_a->next = temp_a->next;
		temp_b = head_b->next;
		temp_a->next = temp_b;
		head_b->next = temp_a;
	}
}
