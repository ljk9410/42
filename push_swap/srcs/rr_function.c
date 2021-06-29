/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:15:46 by jung-lee          #+#    #+#             */
/*   Updated: 2021/06/29 15:54:16 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_struct		*find_last_before(t_struct *node)
{
	t_struct	*temp;

	temp = node;
	if (!temp)
		return (NULL);
	while (temp->next->next != NULL)
		temp = temp->next;
	return (temp);
}

void			rra(t_struct *head_a)
{
	t_struct	*temp;
	t_struct	*last;
	t_struct	*last_before;

	if ((head_a->next != NULL) && (head_a->next->next != NULL))
	{
		temp = head_a->next;
		last = find_lst_last(head_a);
		last_before = find_last_before(head_a);
		head_a->next = last;
		last->next = temp;
		last_before->next = NULL;
	}
	write(1, "rra\n", 4);
}

void			rrb(t_struct *head_b)
{
	t_struct	*temp;
	t_struct	*last;
	t_struct	*last_before;

	if ((head_b->next != NULL) && (head_b->next->next != NULL))
	{
		temp = head_b->next;
		last = find_lst_last(head_b);
		last_before = find_last_before(head_b);
		head_b->next = last;
		last->next = temp;
		last_before->next = NULL;
	}
	write(1, "rrb\n", 4);
}

void			rrr(t_struct *head_a, t_struct *head_b)
{
	rra(head_a);
	rrb(head_b);
	write(1, "rrr\n", 4);
}
