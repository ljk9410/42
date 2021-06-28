/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:13:20 by jung-lee          #+#    #+#             */
/*   Updated: 2021/06/28 14:18:43 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void			check_stack(t_struct *head)
{
	t_struct	*temp;

	temp = head->next;
	printf("stack: ");
	while (temp != NULL)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

void			 b_to_a(t_struct *head_a, t_struct *head_b, int n)
{
	int			pa_cnt;
	int			rb_cnt;
	int			temp;
    int			pivot;

	pa_cnt = 0;
	rb_cnt = 0;
	if (n == 1)
	{
		pa(head_a, head_b);
		return ;
	}
	pivot = check_pivot(head_b, n);
	while (n)
	{
		if (head_b->next->value > pivot)
		{
			pa(head_a, head_b);
			pa_cnt++;
		}
		else
		{
			rb(head_b);
			rb_cnt++;
		}
		n--;
	}
	temp = rb_cnt;
	while (temp)
	{
		rrb(head_b);
		temp--;
	}
	a_to_b(head_a, head_b, pa_cnt);
	b_to_a(head_a, head_b, rb_cnt);
}

void            a_to_b(t_struct *head_a, t_struct *head_b, int n)
{
	int         ra_cnt;
	int         pb_cnt;
	int         temp;
	int			pivot;

	ra_cnt = 0;
	pb_cnt = 0;
	if (n == 1)
		return ;
	pivot = check_pivot(head_a, n);
    while (n)
    {
		if (head_a->next->value > pivot)
        {
            ra(head_a);
            ra_cnt++;
        }
        else
        {
            pb(head_a, head_b);
            pb_cnt++;
        }
        n--;
    }
	temp = ra_cnt;
	while (temp)
	{
		rra(head_a);
		temp--;
	}
	a_to_b(head_a, head_b, ra_cnt);
	b_to_a(head_a, head_b, pb_cnt);
}
